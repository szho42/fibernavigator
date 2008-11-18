#ifndef SURFACE_H_
#define SURFACE_H_

#include "datasetInfo.h"

#include <vector>
#include "Fantom/FTensor.h"
#include "Fantom/FBSplineSurface.h"
#include "DatasetHelper.h"
#include "KdTree.h"
#include "IsoSurface/triangleMesh.h"

class DatasetHelper;

class Surface : public DatasetInfo{

public:
	Surface(DatasetHelper*);
	~Surface();

	bool load(wxString filename) {return false;};
	void draw();
	void generateTexture() {};
	void generateGeometry() {};
	void initializeBuffer() {};
	void createCutTexture();
	void drawVectors();
	void clean() {};
	void smooth() {m_tMesh->doLoopSubD();};

	void movePoints();

	void drawLIC();

	std::vector< std::vector< double > > getSplinePoints() {return m_splinePoints;};
	void setSetSampleRate(float r) {m_sampleRateT = m_sampleRateU = r; execute();};

private:
	void execute();
	FTensor getCovarianceMatrix(std::vector< std::vector< double > > points);
	void getSplineSurfaceDeBoorPoints(  std::vector< std::vector< double > > &givenPoints,
										    std::vector< std::vector< double > > &deBoorPoints,
										    int numRows, int numCols);
	F::FVector getNormalForQuad(const F::FVector*, const F::FVector*, const F::FVector*);

	float getXValue(int y , int z, int numPoints);
	void boxTest(int left, int right, int axis);


	double m_radius;
	double m_my;
	int m_numDeBoorRows;
	int m_numDeBoorCols;
	int m_order;
	double m_sampleRateT;
	double m_sampleRateU;
	double m_xAverage;
	double m_yAverage;
	double m_zAverage;

	std::vector< std::vector< double > > m_splinePoints;

	int m_renderpointsPerCol;
	int m_renderpointsPerRow;
	int m_numPoints;
	float *m_boxMin;
	float *m_boxMax;
	float* m_pointArray;
	float m_xValue;
	int m_count;
	bool licCalculated;

	KdTree *m_kdTree;
	DatasetHelper* m_dh;
	TriangleMesh* m_tMesh;

	std::vector< std::vector<float> >m_testLines;
};


#endif /*SURFACE_H_*/
