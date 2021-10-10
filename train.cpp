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
            isMoving = true;
            return true;
        case LocationStates::AT_STATION_OPEN:
            return false;
        case LocationStates::IN_TUNNEL_MOVE:
            isMoving = false;
            location = LocationStates::AT_STATION_CLOSE;
            return true;
        case LocationStates::IN_TUNNEL_STOP:
            isMoving = true;
            location = LocationStates::IN_TUNNEL_MOVE;
            return true;
        default:
            break;
        }
    }
    else if (signal == Signal::STOP_MOVE)
    {
        if (location == LocationStates::IN_TUNNEL_MOVE){
            location = LocationStates::IN_TUNNEL_STOP;
            isMoving = false;
        }
        return true;
    }
    return false;
}

bool Train::openDoor()
{
    return this->toggleState(Signal::OPEN_DOOR);
}

bool Train::closeDoor()
{
    return this->toggleState(Signal::CLOSE_DOOR);
}

bool Train::startMove()
{
    return this->toggleState(Signal::START_MOVE);
}

bool Train::stopMove()
{
    return this->toggleState(Signal::STOP_MOVE);
}


std::string Train::getLocationStr()
{
    switch (this->location)
    {
    case LocationStates::AT_STATION_CLOSE:
    case LocationStates::AT_STATION_OPEN:
        return "at station";
    case LocationStates::IN_TUNNEL_MOVE:
    case LocationStates::IN_TUNNEL_STOP:
        return "in tunnel";
    default:
        return "";
    }
}

std::ostream& operator<<(std::ostream& stream, Train& obj)
{
    stream << "Status: \n";
    stream << "\t door open: " << std::boolalpha << obj.doorIsOpen << "\n";
    stream << "\t train move: " << std::boolalpha << obj.isMoving << "\n";
    stream << "\t location: " << obj.getLocationStr() << "\n";
    return stream;
}


bool Train::getDoorIsOpen()
{
    return doorIsOpen;
}

bool Train::getIsMoving()
{   
    return isMoving;
}

LocationStates Train::getLocationState()
{
    return location;
}