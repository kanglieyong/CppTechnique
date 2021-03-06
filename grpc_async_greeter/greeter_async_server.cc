#include <iostream>
#include <string>
#include <memory>
#include <thread>

#include <grpc++/grpc++.h>
#include <grpc/support/log.h>

#include <glog/logging.h>

#include "helloworld.grpc.pb.h"

using grpc::Server;
using grpc::ServerAsyncResponseWriter;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerCompletionQueue;
using grpc::Status;

using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;

class ServerImpl {
public:
  ~ServerImpl() {
    server_->Shutdown();
    cq_->Shutdown();
  }

  void Run() {
    std::string server_address("0.0.0.0:50051");
    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service_);
    cq_ = builder.AddCompletionQueue();
    server_ = builder.BuildAndStart();
    std::cout << "Server listening on " << server_address << std::endl;
    HandleRpcs();
  }

private:
  class CallData {
  public:
    CallData(Greeter::AsyncService *service, ServerCompletionQueue *cq)
    : service_(service), cq_(cq), responder_(&ctx_), status_(CREATE) {
      Proceed();
    }

    void Proceed() {
      if (status_ == CREATE) {
        LOG(INFO) << "Status: CREATE" ;
        std::cout << "Status: CREATE" << std::endl;
        status_ = PROCESS;
        service_->RequestSayHello(&ctx_, &request_, &responder_, cq_, cq_, this);
      } else if (status_ == PROCESS) {
        LOG(INFO) << "Status: PROCESS" ;
        std::cout << "Status: PROCESS" << std::endl;
        new CallData(service_, cq_);
        std::string prefix("Hello ");
        reply_.set_message(prefix + request_.name());
        status_ = FINISH;
        responder_.Finish(reply_, Status::OK, this);
      } else {
        LOG(INFO) << "Status: FINISH" ;
        std::cout << "Status: FINISH" << std::endl;
        GPR_ASSERT(status_ == FINISH);
        delete this;
      }
    }
  private:
    Greeter::AsyncService *service_;
    ServerCompletionQueue *cq_;
    ServerContext ctx_;
    HelloRequest request_;
    HelloReply reply_;
    ServerAsyncResponseWriter<HelloReply> responder_;
    enum CallStatus { CREATE, PROCESS, FINISH };
    CallStatus status_;
  };

  void HandleRpcs() {
    new CallData(&service_, cq_.get());
    void *tag;
    bool ok;
    while (true) {
      GPR_ASSERT(cq_->Next(&tag, &ok));
      GPR_ASSERT(ok);
      static_cast<CallData*>(tag)->Proceed();
    }
  }

  std::unique_ptr<ServerCompletionQueue> cq_;
  Greeter::AsyncService service_;
  std::unique_ptr<Server> server_;
};


int main(int argc, char *argv[])
{
  google::InitGoogleLogging(argv[0]);
  //google::SetLogDestination(google::GLOG_INFO, "./log/");

  LOG(INFO) << "Init App";

  ServerImpl server;
  server.Run();

  return 0;
}
