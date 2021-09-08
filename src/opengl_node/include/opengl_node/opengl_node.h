// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"

using std::placeholders::_1;

namespace opengl_node
{
    class OpenglNode : public rclcpp::Node
    {
    public:
        OpenglNode(const rclcpp::NodeOptions & options): Node("opengl_node", options)
        {
            // Set quality of service profile based on command line options.
            auto qos = rclcpp::QoS(
            rclcpp::QoSInitialization(
                history_policy_,
                depth_
            )
            );
            qos.reliability(reliability_policy_);
        }

    private:
        void opengl_sub_callback();

        size_t depth_ = rmw_qos_profile_default.depth;
        rmw_qos_reliability_policy_t reliability_policy_ = rmw_qos_profile_default.reliability;
        rmw_qos_history_policy_t history_policy_ = rmw_qos_profile_default.history;
    };
}  // namespace opengl_node
