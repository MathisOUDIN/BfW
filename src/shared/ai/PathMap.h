// Generated by dia2code
#ifndef AI__PATHMAP__H
#define AI__PATHMAP__H

#include <vector>
#include <queue>

namespace state {
  class Board;
};
namespace ai {
  class Point;
  class PointCompareWeight;
}

#include "Point.h"
#include "state/Board.h"
#include "PointCompareWeight.h"

namespace ai {

  /// class PathMap - 
  class PathMap {
    // Attributes
  protected:
    int width;
    /// 				
    int height;
    std::vector<int> weights;
    std::vector<bool> wall;
    std::priority_queue<Point, std::vector<Point>, PointCompareWeight> queue;
    // Operations
  public:
    void init (const state::Board& board);
    void addWell (Point p);
    void addWall (Point p);
    /// 			
    /// @param board		(???) 
    void update (const state::Board& board);
    const Point getPoint (int x, int y) const;
    const Point getBestPoint (int x, int y) const;
    int getWeight (const Point& p) const;
    /// 	
    /// @param p		(???) 
    void setWeight (const Point& p);
    bool getWall (const Point& p) const;
    void setWall (const Point& p);
    // Setters and Getters
    int getWidth() const;
    void setWidth(int width);
    int getHeight() const;
    void setHeight(int height);
    const std::vector<int>& getWeights() const;
    void setWeights(const std::vector<int>& weights);
    const std::priority_queue<Point, std::vector<Point>, PointCompareWeight>& getQueue() const;
    void setQueue(const std::priority_queue<Point, std::vector<Point>, PointCompareWeight>& queue);
  };

};

#endif
