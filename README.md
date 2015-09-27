# cpp-integration-example

This repository contains our *cpp-integration* as a submodule, so after cloning the repository run the following:

```
  git submodule init
  git submodule update
```

After having done so (*cpp-integration* directory shouldn't be empty anymore), compile using *Make* and execute:

```
  make && ./example
```

**Note:** ZeroMQ and Protocol Buffers should be installed just like with the Profiler itself.
