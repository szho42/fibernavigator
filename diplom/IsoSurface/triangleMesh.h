#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H
/*****************************************************************
*
* TriangleMesh.h
*
* Author:	Russ Stimpson
* Date:		2/7/03
*
*****************************************************************/

#include "Vector.h"
#include <vector>
#include "../DatasetHelper.h"

#define PI 3.14159

class TriangleMesh {

	// Attributes
	private:
		DatasetHelper* m_dh;

		std::vector<Vector> vertices;
		std::vector<Vector> vertNormals;

		std::vector< Vector > triangles;
		std::vector<Vector> triNormals;
		std::vector< int >triangleTensor;

		std::vector < std::vector<int> >vIsInTriangle;

		std::vector< std::vector<int> > neighbors;

		int	numVerts;
		int	numTris;

		bool openMeshError;

		// we don't delete vertices yet, so can do a cleanup only once
		bool isCleaned;

	// Construction
	public:
		TriangleMesh (DatasetHelper* dh);
		~TriangleMesh ();

	// Operations
	public:
		void addVert(Vector newVert);
		void addVert(float x, float y, float z);
		void addTriangle(int vertA, int vertB, int vertC);
		void addTriangle(int vertA, int vertB, int vertC, int tensorIndex);

		Vector calcTriangleNormal(Vector);
		Vector calcTriangleNormal(int triNum);

		void calcVertNormals();
		Vector getVertNormal(int vertNum);

		int calcTriangleTensor(int triNum);
		void calcTriangleTensors();

		int getNeighbor(int coVert1, int coVert2, int triangleNum);
		void calcNeighbors();
		void calcNeighbor(int triangleNum);

		void clearMesh();

		int getNumVertices()					{ return numVerts; };
		int getNumTriangles()					{ return numTris; };
		Vector getVertex (int vertNum) 			{ return vertices[vertNum]; };
		Vector getNormal(int triNum)			{ return triNormals[triNum]; };
		Vector getTriangle(int triNum)			{ return triangles[triNum]; };
		std::vector<int> getStar(int vertNum) 	{ return vIsInTriangle[vertNum]; };
		int getTriangleTensor(int triNum)		{ return triangleTensor[triNum];};

		void setVertex(int vertNum, Vector nPos)	{ vertices[vertNum] = nPos; };
		void eraseTriFromVert( int triNum, int vertNum);

		void setTriangle(int triNum, int vertA, int vertB, int vertC);

		bool isInTriangle(int vertNum, int triangleNum);

		bool hasEdge(int coVert1, int coVert2, int triangleNum);
		int getThirdVert(int coVert1, int coVert2, int triangleNum);


		int** removeTriangles();

		int getNextVertex(int triNum, int vertNum);

		bool getOpenMeshError() { return openMeshError; };

		void cleanUp();

		void doLoopSubD();


	private:


	// Overrides

	// Implementation
};
#endif
