#include <akit/LoggedRobot.h>
#include <akit/Logger.h>
#include <akit/networktables/NT4Publisher.h>
#include <wpi/print.h>
#include <wpi/timestamp.h>
#include <frc/DataLogManager.h>
#include "akit/wpilog/WPILOGWriter.h"
#include "akit/wpilog/WPILOGReader.h"

class Robot : public akit::LoggedRobot {
    public:
    Robot() {
        akit::Logger::SetReplaySource(std::make_unique<akit::wpilog::WPILOGReader>("logs/akit_6a4bc925e3ac3bbc.wpilog"));
        // akit::Logger::AddDataReceiver(std::make_unique<akit::wpilog::WPILOGWriter>());
        akit::Logger::Start();
    }

    void RobotPeriodic() override {}
};

int main() {
    return frc::StartRobot<Robot>();
}