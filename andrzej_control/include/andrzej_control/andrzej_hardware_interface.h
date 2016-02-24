#include <memory>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>

#include "joint_hardware_interface.h"
#include "PCA9685.h"

class AndrzejHardwareInterface : public hardware_interface::RobotHW
{
public:
    AndrzejHardwareInterface();

    void write(void);
    void read(void);

private:
    static const int JOINTS_PER_ARM = 5;

    hardware_interface::JointStateInterface jointStateInterface;
    hardware_interface::PositionJointInterface jointPosInterface;

    std::array<JointHardwareInterface, JOINTS_PER_ARM> arm_1, arm_2;

    PCA9685Ptr pwmDriverPtr;
};