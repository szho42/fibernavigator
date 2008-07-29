#ifndef SELECTIONBOX_H_
#define SELECTIONBOX_H_

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "GL/glew.h"
#include "ArcBall.h"
#include "boundingBox.h"
#include <vector>
#include "DatasetHelper.h"

class MainCanvas;
class Curves;
class DatasetHelper;

class SelectionBox {
public:
	SelectionBox(Vector3fT, Vector3fT, DatasetHelper*);
	SelectionBox(SelectionBox*);
	~SelectionBox() {};

	void drawHandles();
	void drawFrame();
	hitResult hitTest(Ray *ray);
	void processDrag(wxPoint click, wxPoint lastPos);

	bool toggleShow() {return m_show = !m_show;};
	bool toggleNOT() {return m_isNOT = !m_isNOT;};
	bool getShow() {return m_show;};

	void setCenter(Vector3fT c) { m_center = c; m_dirty = true;};
	Vector3fT getCenter() {return m_center;};
	void setSize(Vector3fT v) {m_size = v;m_dirty = true;};
	Vector3fT getSize() {return m_size;};
	void setPicked(int s) {m_hr.picked = s;};
	bool isDirty() {return m_dirty;};
	void setDirty() {m_dirty = true;};
	void notDirty() {m_dirty = false;};
	bool colorChanged() {return m_colorChanged;};
	wxColour getColor() {return m_color;};
	void setColorChanged(bool v) {m_colorChanged = v;};

	void draw1();
	void draw2();
	void draw3();
	void draw4();
	void draw5();
	void draw6();

	void moveLeft();
	void moveRight();
	void moveForward();
	void moveBack();
	void moveUp();
	void moveDown();

	void resizeLeft();
	void resizeRight();
	void resizeForward();
	void resizeBack();
	void resizeUp();
	void resizeDown();

	void setColor(wxColour);

	void update();

	std::vector<bool>m_inBox;

	bool m_isNOT;
	bool m_isTop;
	bool m_isActive;

	DatasetHelper* m_dh;

private:
	void drawSphere(float, float, float, float);
	void drag(wxPoint click);
	void resize(wxPoint click, wxPoint lastPos);

	float getAxisParallelMovement(int, int, int, int, Vector3fT);

	Vector3fT m_center;
	Vector3fT m_size;
	hitResult m_hr;
	float mx, px, my, py, mz, pz;

	float m_handleRadius;
	bool m_show;
	bool m_dirty;
	bool m_colorChanged;
	wxColour m_color;

};

#endif /*SELECTIONBOX_H_*/
