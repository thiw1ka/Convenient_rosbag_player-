#include "bag_player/bag_player.hpp"

int main () {

    bag_player bp;
    std::string fpath = "/home/thivanka/catkin_ws/src/uri_soft_wip/cyanobloom_sabbatus/cyanobloom_phd_filter_sabbatus/results/2.Rosbags/2022-03-25-11-58-13_NEwind.bag";

    bp.set_bagpath(fpath);

    bp.play();
    

    return 0;
}