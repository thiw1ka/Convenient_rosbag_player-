#include <iostream>
#include "rosbag/bag.h"
#include <rosbag/view.h>
#include "rosbag/bag_player.h"

#include <cstdlib>
#include <future>

#ifndef BAG_PLAYER_HPP
#define BAG_PLAYER_HPP

/**
 * @brief this class takes a rosbag and play it. the playing will be done at user request by threads.
 * 
 */
class bag_player {

    public:

        bag_player();

        bag_player(std::string path, double speed);

        void set_bagpath (std::string fpath);

        void set_bagspeed (double speed);

        void play ();

        ~bag_player();


    private:
        std::string filepath;

        std::string play_speed = "1.0 ";

    protected:

        // rosbag::Bag bag;
        // rosbag::BagPlayer* player;

        std::unique_ptr<rosbag::BagPlayer> player;


};

#endif