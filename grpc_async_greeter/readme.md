## generate protobuf code command
```
protoc --cpp_out=. helloworld.proto
```

## generate grpc code command
```
protoc --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` helloworld.proto
```

## compile server command
```
g++ -std=c++11 greeter_async_server.cc helloworld.grpc.pb.cc helloworld.pb.cc \
    -lprotobuf -lgrpc -lgrpc++ -pthread \
    -o async_server.out
```

## compile client command
```
g++ -std=c++11 greeter_async_client1.cc helloworld.grpc.pb.cc helloworld.pb.cc \
    -lprotobuf -lgrpc -lgrpc++ -pthread \
    -o async_client1.out
```
