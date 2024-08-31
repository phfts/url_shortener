# Url Shortener

A simple but scalable microservice to create short urls.

Local performance tests shows it can handle well 50k link creation requests with 1k concurrent users. In this scenario the throughput is 5k requests per second.

## Dependencies
1. Mongodb c++ drivers
2. Crow http server (as gitsubmodule inside libs)
3. Google Test Library (for testing)

## Running tests
``` 
$ make test
```

## Running load tests
```
$ make load-test
```

## Next steps
1. Observability
2. Creating a frontend
3. Using docker/k8s to scale
4. User, accounts and billing
5. Create expiry policies for free and paying users (e.g.: per time, per use)
6. Add analytics capabilities for paying users
7. Enhace libs dependency install and update workflow
8. Optimize performance
