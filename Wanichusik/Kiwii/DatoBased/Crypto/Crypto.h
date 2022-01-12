#include "../Deep/Deep.h"

namespace Kiwii {
    class Crypto : public Deep {
        //if there are pointers,
        //then on each pointer need one boolean
        //(ask, if decleared, with class, when it hasn't got not empty constructor) 

        ///////pointers////////

        ////others variables///


        ///////pointers////////
        bool is_decleared = false;

    public:
        //////constructor//////
        Crypto() {}

        //////get and set//////
        void setup(uint16_t width, uint16_t height, bool have_void = true) {}

        ////////virtual////////

        ///////override////////
        void _info_r(std::string _name_r) override;

        /////special func//////



        void unsetup() {}

        ///////destructor//////
        ~Crypto() {
            unsetup();
        }

    };
}
