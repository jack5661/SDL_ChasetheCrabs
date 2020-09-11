#include "CollisionDetector.h"

bool CollisionDetector::RectCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
	return (std::max(x1, x2) < std::min(x1 + w1, x2 + w2)) && (std::max(y1, y2) < std::min(y1 + h1, y2 + h2));
}