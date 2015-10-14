#include "cpp-integration/connector.hh"

int main() {

  using Profiling::Node;
  using Profiling::NodeStatus;

  /// Instantiate a Connector with 6565 as port
  Profiling::Connector c(6565);
  c.connect();

  /// Starting a new tree (also used in case of a restart)
  c.restart("minimal example");

  /// SEND ROOT NODE

  /// Arguments:
  /// 1. 0 -- node index;
  /// 2. -1 -- parent's index (-1 indicates that the parent does not exist)
  /// 3. -1 -- parent's current alternative (normally starts with 0, but -1 as irrelevant here)
  /// 4.  2 -- number of children nodes (as in binary tree)
  /// 5.  NodeStatus::BRANCH -- decision node / node with children
  /// The rest of fields are optional and can be specified in arbitrary order
  c.createNode(0, -1, -1, 2, NodeStatus::BRANCH).set_label("root").send();

  // SEND LEFT CHILD
  c.createNode(1, 0, 0, 0, NodeStatus::FAILED).set_label("a").send();

  // SEND RIGHT CHILD
  c.createNode(2, 0, 1, 0, NodeStatus::SOLVED).set_label("b").send();

  c.done();
  c.disconnect();
}