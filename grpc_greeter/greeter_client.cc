#include <iostream>
#include <string>
#include <memory>

#include <grpc++/grpc++.h>

#include "helloworld.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
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
    Status status = stub_->SayHello(&context, request, &reply);
    if (status.ok()) {
      return reply.message();
    } else {
      std::cout << status.error_code() << ": " << status.error_message() << std::endl;
      return "Rpc failed";
    }
  }

private:
  std::unique_ptr<Greeter::Stub> stub_;
};

int main()
{
  GreeterClient greeter( grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()) );
  std::string user("world");
  std::string reply = greeter.SayHello(user);
  std::cout << "Greeter received: " << reply << std::endl;

  return 0;
}
