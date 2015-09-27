#include <iostream>
#include "cpp-integration/connector.hh"

int main() {

  using Profiling::Node;
  using Profiling::NodeStatus;

  Profiling::Connector c(6565);
  c.connect();

  c.restart(-1, "test example");

  // send root node
  c.sendNode(0, -1, -1, 2, NodeStatus::BRANCH, "root", -1);

  // send left child
  c.sendNode(1, 0, 0, 0, NodeStatus::FAILED, "a", -1);

  Node node(2, 0, 1, 0, NodeStatus::SOLVED);

  node.set_label("b");
  node.set_thread_id(-1);

  c.sendNode(node);

  c.done();
  c.disconnect();
}