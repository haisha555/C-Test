#include "Timer.h"
#include "Octree.h"

std::vector<Vector3> points;
Octree* octree;
Vector3* octreePoints;
Vector3 qmin, qmax;

float rand11()
{
	return -1.f + (2.f * rand()) * (1.f / RAND_MAX);
}

Vector3 randVec3() // Random vector with components in the range [-1,1]
{
	return Vector3(rand11(), rand11(), rand11());
}


bool naivePointInBox(const Vector3& point, const Vector3& bmin, const Vector3& bmax) {
	return
		point.x >= bmin.x &&
		point.y >= bmin.y &&
		point.z >= bmin.z &&
		point.x <= bmax.x &&
		point.y <= bmax.y &&
		point.z <= bmax.z;
}

void init() {
	octree = new Octree(Vector3(0, 0, 0), Vector3(1, 1, 1));
	const int nPoints = 1 * 1000 * 1000;
	for (int i = 0; i < nPoints; ++i) {
		points.push_back(randVec3());
	}
	printf("Created %ld points\n", points.size()); fflush(stdout);
	octreePoints = new Vector3[nPoints];
	for (int i = 0; i < nPoints; ++i) {
		octreePoints[i] = points[i];
		octree->insert(octreePoints + i);
	}
	printf("Inserted points to octree\n"); fflush(stdout);
	qmin = Vector3(-.05, -.05, -.05);
	qmax = Vector3(.05, .05, .05);
}

void testNaive() {
	double start = stopwatch();
	std::vector<int> results;
	for (int i = 0; i < points.size(); ++i) {
		if (naivePointInBox(points[i], qmin, qmax)) {
			results.push_back(i);
		}
	}
	double T = stopwatch() - start;
	printf("testNaive found %ld points in %.5f sec.\n", results.size(), T);
}

void testOctree() {
	double start = stopwatch();

	std::vector<Vector3*> results;
	octree->getPointsInsideBox(qmin, qmax, results);

	double T = stopwatch() - start;
	printf("testOctree found %ld points in %.5f sec.\n", results.size(), T);
}


int main(int argc, char** argv) {
	init();
	testNaive();
	testOctree();

	return 0;
}