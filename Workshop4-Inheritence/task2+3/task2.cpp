#include <iostream>
#include "Robot.h"
#include "SocialRobot.h"
#include "IndustrialRobot.h"
#include "AutonomousCar.h"

int main(){
    
    // Robot robot1("Default Robo.");
    // SocialRobot robot2("Default Social Robo.");
    // IndustrialRobot robot3("Default Industrial Robo.");
    // AutonomousCar robot4("Default Autonomous Car.");

    // robot1.work();
    // robot2.work();
    // robot3.workHarder();

    // Robot robots[4] = {robot1, robot2, robot3, robot4};

    // for(const auto& robot : robots){
    //     std::cout << robot.whoAmI() << "\n";
    // }

    // robot4.UpdateLocation(10, 10);
    // robot4.work();

    // WEEK 7 TASK 5 //
    Robot r2("Task5 Robo");
    {
        Robot r1("r1");
        r1.whoAmI();
        r1.work();
        r1.work();
        r1.printWork();
        std::cout << "assign r1 to r2..." << std::endl;
        r2 = r1;
        r2.setName("r2");
        r2.whoAmI();
        r2.printWork();
    }
    r2.whoAmI();
    r2.printWork();
    std::cout << "end of example code..." << std::endl;


    return 0;
}