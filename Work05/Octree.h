#pragma once
#include "Vector3.h"
#include <vector>;

class Octree
{
public:
	Vector3 Origin;
	Vector3* Position;
	Vector3 HalfDimension;
	Octree* Children[8];

	Octree(Vector3 origin, Vector3 halfDimension): Origin(origin), HalfDimension(halfDimension), Position(nullptr){
		for (int i = 0; i < 8; i++) {
			Children[i] = nullptr;
		}
	}

	Octree(Octree& octree)
		: Origin(octree.Origin), HalfDimension(octree.HalfDimension), Position(octree.Position) {

	}

	~Octree() {
		for (int i = 0; i < 8; i++) {
			delete Children[i];
		}
	}

	int GetTargetPositionContaining(const Vector3& TargetPosition) {
		int ChildIdex = 0;
		if (TargetPosition.x >= Origin.x) ChildIdex += 4;
		if (TargetPosition.y >= Origin.y) ChildIdex += 2;
		if (TargetPosition.z >= Origin.z) ChildIdex += 1;
		return ChildIdex;
	}

	bool IsLeafNode() {
		return Children[0] == nullptr;
	}

	void insert(Vector3* InsertPosition) {
		if (IsLeafNode()) {
			if (Position == nullptr) {
				Position = InsertPosition;
				return;
			}
			else {
				Vector3* OldPosition = Position;
				Position = nullptr;
				for (int i = 0; i < 8; ++i) {
					Vector3 newOrigin = Origin;
					newOrigin.x += HalfDimension.x * (i & 4 ? .5f : -.5f);
					newOrigin.y += HalfDimension.y * (i & 2 ? .5f : -.5f);
					newOrigin.z += HalfDimension.z * (i & 1 ? .5f : -.5f);
					Children[i] = new Octree(newOrigin, (HalfDimension * .5f));
				}
				Children[GetTargetPositionContaining(*OldPosition)]->insert(OldPosition);
				Children[GetTargetPositionContaining(*InsertPosition)]->insert(InsertPosition);
			}
		}
		else {
			Children[GetTargetPositionContaining(*InsertPosition)]->insert(InsertPosition);
		}

	}
	void getPointsInsideBox(const Vector3& bmin, const Vector3& bmax, std::vector<Vector3*>& results) {
		if (IsLeafNode()) {
			if (Position != nullptr) {
				const Vector3& p = *Position;
				if (p.x > bmax.x || p.y > bmax.y || p.z > bmax.z) return;
				if (p.x < bmin.x || p.y < bmin.y || p.z < bmin.z) return;
				results.push_back(Position);
			}
		}
		else {
			for (int i = 0; i < 8; ++i) {
				Vector3 cmax = (Children[i]->Origin) + (Children[i]->HalfDimension);
				Vector3 cmin = (Children[i]->Origin) - (Children[i]->HalfDimension);
				if (cmax.x < bmin.x || cmax.y < bmin.y || cmax.z < bmin.z) continue;
				if (cmin.x > bmax.x || cmin.y > bmax.y || cmin.z > bmax.z) continue;
				Children[i]->getPointsInsideBox(bmin, bmax, results);
			}
		}
	}

};

