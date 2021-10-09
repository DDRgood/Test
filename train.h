#include <iostream>

enum LocationStates
{
    AT_STATION_OPEN,
    AT_STATION_CLOSE,
    IN_TUNNEL_MOVE,
    IN_TUNNEL_STOP
};

enum Signal
{
    START_MOVE,
    STOP_MOVE,
    OPEN_DOOR,
    CLOSE_DOOR
}

class Train
{
    private:
        enum LocationStates location;
        bool doorIsOpen;
        bool isMoving;
        bool checkState();
        bool toggleState(Signal signal);

    public:
        Train(LocationStates state, bool door, bool move);
        Train();
        bool openDoor();
        void closeDoor();
        bool startMove();
        void stopMove();
};