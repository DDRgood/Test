#include "train.h"


Train::Train(LocationStates state)
{
    location = state;
    switch (state)
    {
    case LocationStates::AT_STATION_OPEN:
        isMoving = false;
        doorIsOpen = true;
        break;
    case LocationStates::AT_STATION_CLOSE:
        isMoving = false;
        doorIsOpen = false;
        break;
    case LocationStates::IN_TUNNEL_MOVE:
        isMoving = true;
        doorIsOpen = false;
        break;
    case LocationStates::IN_TUNNEL_STOP:
        isMoving = false;
        doorIsOpen = false;
    default:
        break;
    }
}


bool Train::checkState()
{  
}

Train::Train()
    : location(LocationStates::AT_STATION_OPEN), doorIsOpen(true), isMoving(false)
{}

bool Train::toggleState(Signal signal)
{
    if (signal == Signal::OPEN_DOOR)
    {
        switch (location)
        {
        case LocationStates::IN_TUNNEL_MOVE:
        case LocationStates::IN_TUNNEL_STOP:
            return false;
            break;
        case LocationStates::AT_STATION_CLOSE:
            location = LocationStates::AT_STATION_OPEN;
            doorIsOpen = true;
            return true;
        case LocationStates::AT_STATION_OPEN:
            doorIsOpen = true;
            return true;
        default:
            break;
        }
    }
    else if (signal == Signal::CLOSE_DOOR)
    {
        if (location == LocationStates::AT_STATION_OPEN)
            location = LocationStates::AT_STATION_CLOSE;
        doorIsOpen = false;
        return true;
    }
    else if (signal == Signal::START_MOVE)
    {
        switch (location)
        {
        case LocationStates::AT_STATION_CLOSE:
            location = LocationStates::IN_TUNNEL_MOVE;
            return true;
            break;
        case LocationStates::AT_STATION_OPEN:
            return false;
            break;
        case LocationStates::IN_TUNNEL_MOVE:
            location = LocationStates::AT_STATION_CLOSE;
            return true;
            break;
        case LocationStates::IN_TUNNEL_STOP:
            location = LocationStates::IN_TUNNEL_MOVE;
            return true;
        default:
            break;
        }
    }
    else if (signal == Signal::STOP_MOVE)
    {

    }
    else{}
}

bool Train::openDoor()
{
    return this->toggleState(Signal::OPEN_DOOR);
}

void Train::closeDoor()
{
    doorIsOpen = false;
}

bool Train::startMove()
{
    if (doorIsOpen) return false;
    else isMoving = true;
    return true;
}

void Train::stopMove()
{
    isMoving = false;
}
