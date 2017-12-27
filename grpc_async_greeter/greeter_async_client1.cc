#include <iostream>
#include <string>
#include <memory>

#include <grpc++/grpc++.h>
#include "helloworld.grpc.pb.h"

using grpc::Channel;
using grpc::ClientAsyncResponseReader;
using grpc::ClientContext;
using grpc::CompletionQueue;
using grpc::Status;

using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;

class GreeterClient {
public:
  GreeterClient(std::shared_ptr<Channel> channel)
    : stub_(Greeter::NewStub(channel)) {}

  std::string SayHello(const std::string &user) {
    HelloRequest request;
    request.set_name(user);
    HelloReply reply;
    ClientContext context;

    // async
    CompletionQueue cq;
    Status status;

    std::unique_ptr<ClientAsyncResponseReader<HelloReply> > rpc(stub_->PrepareAsyncSayHello(&context, request, &cq));
    rpc->StartCall();

    //Status status = stub_->SayHello(&context, request, &reply);
    rpc->Finish(&reply, &status, (void*)1);

    void *got_tag;
    bool ok = false;

    cq.Next(&got_tag, &ok);
    if (ok && got_tag == (void*)1) {
      if (status.ok()) {
        return reply.message();
      } else {
        std::cout << status.error_code() << ": " << status.error_message() << std::endl;
        return "RPC failed";
      }
    }
    return "RPC failed too";
}

private:
  std::unique_ptr<Greeter::Stub> stub_;
};

int main()
{
  GreeterClient greeter(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
  std::string user("Peng Shasha");
  std::string reply = greeter.SayHello(user);
  std::cout << "Greeter received: " << reply << std::endl;

  return 0;
}
