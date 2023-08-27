#include "bag_player/bag_player.hpp"

bag_player::bag_player() {
    std::printf("[bag_player] bag player starting \n");
    ///home/thivanka/catkin_ws/src/uri_soft_wip/cyanobloom_sabbatus/cyanobloom_phd_filter_sabbatus/results/2.Rosbags/2022-03-25-11-58-13_NEwind.bag
}

bag_player::bag_player(std::string path, double speed = 1.0) {
    bag_player();
    bag_player::set_bagpath (path);
    set_bagspeed(speed);
}

void bag_player::set_bagpath (std::string fpath) {
    /**setting bag path*/
    /*usign rosplayer to check if the path is valid for a bag*/
    std::printf("[bag_player] setting bag path \n");
    try {
        filepath = fpath;
        player.reset(new rosbag::BagPlayer(filepath));
    }
    catch (...) {
        std::cout << "[bagplayer] Error in set bag path. path is incorrect: " <<filepath<<"\n" ;
        exit(0);
    }
}

void bag_player::set_bagspeed (double speed = 1.0) {
    std::printf("[bag_player] setting bag speed \n");
    // player->set_playback_speed (speed); //no longer needed
    play_speed = std::to_string(speed) + " ";
}

/*ros bag will be played using threads*/
void bag_player::play () {
    try {
        std::printf("[bag_player::play] bag is playing \n");
        // std::string cmd = "rosbag play -u 1000 -r " + play_speed + filepath; ///TODO mute verbose
         std::string cmd = "rosbag play -q -r " + play_speed + filepath;
        // auto retrun_val = std::system(cmd.c_str());
        /*async will try to run the task using multiple threads*/
        auto future_return = std::async( std::launch::async, &std::system, cmd.c_str());
        std::printf("[bag_player::play] rosbag asyn started. waiting till it finish.\n");
        std::cout <<"[bag_player::play] robag running completed : " <<future_return.get() << std::endl;
        ///TODO maybe RETURN something to inform play is done
    }
    catch (std::exception &a) {
        /*remember future will capture the execption and rethrow during .get()*/
        std::cout <<"[bag_player::play] Error exception thrown. \n";
        std::cout << a.what() <<std::endl;
    }
}

bag_player::~bag_player () {
    std::printf("[bag_player] ~bag_player () \n");
}
