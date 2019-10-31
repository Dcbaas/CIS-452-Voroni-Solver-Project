#pragma once

#include <map>
#include <mutex>

using seed = int;

class Coordinate{
public:
    Coordinate(const int x, const int y);
    size_t findDistance(const Coordinate& other);
    int x;
    int y;
};

struct coordCompare{
    bool operator()(const Coordinate& lhs, const Coordinate& rhs)const{
        if(lhs.x != rhs.x){
            return lhs.x < rhs.x;
        }
        return (lhs.x * lhs.y) < (rhs.x * rhs.y);
    }
};

using CoordinateSeedMap = std::map<Coordinate, seed, coordCompare>;

class VoroniStructures{
public:
    VoroniStructures(std::map<seed, Coordinate>& seedToLocationMap);
    void addCoordinate(const int x, const int y);
    CoordinateSeedMap& getCoordinateToSeedMap()const;
private:
    // This structure holds the entire bitmap and represents what seed a coordinate is closest to.
    CoordinateSeedMap coordinateToSeedMap;

    // This structre represents  the seeds and where they are located.
    std::map<seed, Coordinate> seedToLocationMap;

    static std::mutex structuresLock;
};


