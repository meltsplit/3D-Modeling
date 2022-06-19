#include "HW3.h"
#include "Scene.h"

#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

struct ModelViewer : Window
{
	ModelViewer(Point xy, int w, int h, const string& title);
	~ModelViewer();

private:
	int win_width = 0;
	int win_height = 0;

	Scene* scene = nullptr;

	float cam_dist = 1.0f;
	float cam_phi = 0.0f;
	float cam_theta = 0.0f;

	Color color = Color::black;                           //Color 멤버 변수

	void renderScene(Color color);                        // renderScene함수에 Color 인자 추가

	
	Button load_cube_button;
	Button load_bunny_button;
	Button load_teapot_button;
	Button zoom_in_button;
	Button zoom_out_button;
	Button move_left_button;
	Button move_right_button;
	Button move_up_button;
	Button move_down_button;
	Button cull_button;
	Button exit_button;

	Button red_button;                       //Color Button
	Button green_button;
	Button blue_button;
	Button white_button;
	Button black_button;                   

	Button reset_button;				     //Reset Button

	Button move_Left30_button;               //Move 30 degree Button
	Button move_Right30_button;              
	Button move_Up30_button;	             
	Button move_Down30_button;               

	void loadCube();
	void loadBunny();
	void loadTeapot();
	void loadArmadillo();
	void zoomIn();
	void zoomOut();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void cull();
	void exit();

	void makeRed();                            // Color Method
	void makeGreen();
	void makeBlue();
	void makeWhite();
	void makeBlack();   

	void reset();                              // reset Method

	void moveLeft30();                         // 30 degree Method
	void moveRight30();
	void moveUp30();
	void moveDown30();

	static void cb_loadCube(Address, Address window);
	static void cb_loadBunny(Address, Address window);
	static void cb_loadTeapot(Address, Address window);
	static void cb_loadArmadillo(Address, Address window);
	static void cb_zoomIn(Address, Address window);
	static void cb_zoomOut(Address, Address window);
	static void cb_moveLeft(Address, Address window);
	static void cb_moveRight(Address, Address window);
	static void cb_moveUp(Address, Address window);
	static void cb_moveDown(Address, Address window);
	static void cb_cull(Address, Address window);
	static void cb_exit(Address, Address window);

	static void cb_red(Address, Address window);                   //Color Address
	static void cb_green(Address, Address window);
	static void cb_blue(Address, Address window);
	static void cb_white(Address, Address window);
	static void cb_black(Address, Address window);                  

	static void cb_reset(Address, Address window);			       //Reset Address	  

	static void cb_moveLeft30(Address, Address window);            //30 degree Address 
	static void cb_moveRight30(Address, Address window);
	static void cb_moveUp30(Address, Address window);
	static void cb_moveDown30(Address, Address window);
};

ModelViewer::ModelViewer(Point xy, int w, int h, const string& title)
	: Window(xy, w, h, title),
	win_width(w),
	win_height(h),
	load_cube_button(Point(10,10), 70, 20, "Cube", cb_loadCube),
	load_bunny_button(Point(90,10), 70, 20, "Bunny", cb_loadBunny),
	load_teapot_button(Point(170,10), 70, 20, "Teapot", cb_loadTeapot),
	zoom_in_button(Point(400,10), 70, 20, "In", cb_zoomIn),
	zoom_out_button(Point(480,10), 70, 20, "Out", cb_zoomOut),
	move_left_button(Point(560,10), 70, 20, "Left", cb_moveLeft),
	move_right_button(Point(640,10), 70, 20, "Right", cb_moveRight),
	move_up_button(Point(720,10), 70, 20, "Up", cb_moveUp),
	move_down_button(Point(800,10), 70, 20, "Down", cb_moveDown),
	cull_button(Point(w-160, 10), 70, 20, "Cull", cb_cull),
	exit_button(Point(w-80,10), 70, 20, "Exit", cb_exit),

	red_button(Point(240, 260), 60, 60, "Red", cb_red),                         // Color Layout
	green_button(Point(240, 340), 60, 60, "Green", cb_green),
	blue_button(Point(240, 420), 60, 60, "Blue", cb_blue),
	white_button(Point(240, 500), 60, 60, "White", cb_white),
	black_button(Point(240, 580), 60, 60, "Black", cb_black),
	
	reset_button(Point(600, 750), 60, 60, "Reset", cb_reset),				    //Reset Layout

	move_Left30_button(Point(1000, 340), 60, 60, "Left30", cb_moveLeft30),      // 30 degree Layout
	move_Right30_button(Point(1000, 420), 60, 60, "Right30", cb_moveRight30),
	move_Up30_button(Point(1000, 500), 60, 60, "Up30", cb_moveUp30),
	move_Down30_button(Point(1000, 580), 60, 60, "Down30", cb_moveDown30)



{	
	attach(load_cube_button);
	attach(load_bunny_button);
	attach(load_teapot_button);
	attach(zoom_in_button);
	attach(zoom_out_button);
	attach(move_left_button);
	attach(move_right_button);
	attach(move_up_button);
	attach(move_down_button);
	attach(cull_button);
	attach(exit_button);

	attach(red_button);                                                        // Color Attach
	attach(green_button);                                                       
	attach(blue_button);
	attach(white_button);
	attach(black_button);

	attach(reset_button);														// Reset Attach

	attach(move_Left30_button);                                                // 30 Degree Attach
	attach(move_Right30_button);
	attach(move_Up30_button);
	attach(move_Down30_button);

	scene = new Scene(this);
	scene->addMesh(Geometry::CUBE);

	cam_dist = 3.0f;
	cam_phi = 0.0f;
	cam_theta = radian_from_degree(90.0f);

	color = Color::black;

	renderScene(color);
}

ModelViewer::~ModelViewer()
{
	delete scene;
}

void ModelViewer::renderScene(Color color)                              //render함수에게 color 인자를 받아 색상을 결정하게 함
{
	float cam_x = cam_dist * cosf(cam_phi) * sinf(cam_theta);
	float cam_z = cam_dist * sinf(cam_phi) * sinf(cam_theta);
	float cam_y = cam_dist * cosf(cam_theta);

	scene->setLookAt(Vector3(cam_x, cam_y, cam_z), Vector3(0, 0, 0), Vector3(0, 1, 0));
	scene->setPerspective(radian_from_degree(45.0f), (float)win_width / (float)win_height, 1.0f, 100.0f);
	scene->render(color);

	redraw();
}

void ModelViewer::loadCube()
{
	scene->removeAllMeshes();
	scene->addMesh(Geometry::CUBE);

	renderScene(color);
}

void ModelViewer::loadBunny()
{
	scene->removeAllMeshes();
	scene->addMesh("bunny.txt");

	renderScene(color);
}

void ModelViewer::loadTeapot()
{
	scene->removeAllMeshes();
	scene->addMesh("teapot.txt");

	renderScene(color);
}

void ModelViewer::loadArmadillo()
{
	scene->removeAllMeshes();
	scene->addMesh("armadillo.txt");

	renderScene(color);
}

void ModelViewer::zoomIn()
{
	float d = 0.25f;
	if (cam_dist > d)
	{
		cam_dist -= d;
		renderScene(color);
	}
}

void ModelViewer::zoomOut()
{
	float d = 0.25f;
	cam_dist += d;
	renderScene(color);
}

void ModelViewer::moveLeft()
{
	float da = radian_from_degree(5.0f);
	cam_phi += da;
	renderScene(color);
}

void ModelViewer::moveRight()
{
	float da = radian_from_degree(5.0f);
	cam_phi -= da;
	renderScene(color);
}

void ModelViewer::moveUp()
{
	float da = radian_from_degree(5.0f);
	if (cam_theta > da)
	{
		cam_theta -= da;
		renderScene(color);
	}
}

void ModelViewer::moveDown()
{
	float da = radian_from_degree(5.0f);
	if (cam_theta <= radian_from_degree(90.0f) - da)
	{
		cam_theta += da;
		renderScene(color);
	}
}

void ModelViewer::cull()
{
	scene->toggleCulling();
	renderScene(color);
}

void ModelViewer::exit()
{
	hide();
}
                                    
void ModelViewer::makeRed()                 //Color Definition
{
	color = Color::red;
	renderScene(color);
}

void ModelViewer::makeGreen()
{
	color = Color::green;
	renderScene(color);
}

void ModelViewer::makeBlue()
{
	color = Color::blue;
	renderScene(color);
}
 
void ModelViewer::makeWhite()
{
	color = Color::white;
	renderScene(color);
}
void ModelViewer::makeBlack()
{
	color = Color::black;
	renderScene(color);
}



void ModelViewer::reset()                   //   Reset Definition
{
	cam_dist = 3.0f;
	cam_phi = 0.0f;
	cam_theta = radian_from_degree(90.0f);
	color = Color::black; 
	renderScene(color);
}



void ModelViewer::moveLeft30()                 //30 Degree Definition
{
	float da = radian_from_degree(30.0f);
	cam_phi += da;
	renderScene(color);
}

void ModelViewer::moveRight30()
{
	float da = radian_from_degree(30.0f);
	cam_phi -= da;
	renderScene(color);
}

void ModelViewer::moveUp30()
{
	float da = radian_from_degree(30.0f);
	if (cam_theta > da)
	{
		cam_theta -= da;
		renderScene(color);
	}
}

void ModelViewer::moveDown30()
{
	float da = radian_from_degree(30.0f);
	if (cam_theta <= radian_from_degree(90.0f) - da)
	{
		cam_theta += da;
		renderScene(color);
	}
}



void ModelViewer::cb_loadCube(Address, Address pw)
{
	reference_to<ModelViewer>(pw).loadCube();
}

void ModelViewer::cb_loadBunny(Address, Address pw)
{
	reference_to<ModelViewer>(pw).loadBunny();
}

void ModelViewer::cb_loadTeapot(Address, Address pw)
{
	reference_to<ModelViewer>(pw).loadTeapot();
}

void ModelViewer::cb_loadArmadillo(Address, Address pw)
{
	reference_to<ModelViewer>(pw).loadArmadillo();
}

void ModelViewer::cb_zoomIn(Address, Address pw)
{
	reference_to<ModelViewer>(pw).zoomIn();
}

void ModelViewer::cb_zoomOut(Address, Address pw)
{
	reference_to<ModelViewer>(pw).zoomOut();
}

void ModelViewer::cb_moveLeft(Address, Address pw)
{
	reference_to<ModelViewer>(pw).moveLeft();
}

void ModelViewer::cb_moveRight(Address, Address pw)
{
	reference_to<ModelViewer>(pw).moveRight();
}

void ModelViewer::cb_moveUp(Address, Address pw)
{
	reference_to<ModelViewer>(pw).moveUp();
}

void ModelViewer::cb_moveDown(Address, Address pw)
{
	reference_to<ModelViewer>(pw).moveDown();
}

void ModelViewer::cb_cull(Address, Address pw)
{
	reference_to<ModelViewer>(pw).cull();
}

void ModelViewer::cb_exit(Address, Address pw)
{
	reference_to<ModelViewer>(pw).exit();
}


void ModelViewer::cb_red(Address, Address pw)            //Color Address Definition
{
	reference_to<ModelViewer>(pw).makeRed();
}
void ModelViewer::cb_green(Address, Address pw)
{
	reference_to<ModelViewer>(pw).makeGreen();
}
void ModelViewer::cb_blue(Address, Address pw)
{
	reference_to<ModelViewer>(pw).makeBlue();
}
void ModelViewer::cb_white(Address, Address pw)
{
	reference_to<ModelViewer>(pw).makeWhite();
}
void ModelViewer::cb_black(Address, Address pw)
{
	reference_to<ModelViewer>(pw).makeBlack();
}


void ModelViewer::cb_reset(Address, Address pw)                   //Reset Address Definition
{
	reference_to<ModelViewer>(pw).reset();
}


void ModelViewer::cb_moveLeft30(Address, Address pw)              //30 degree Address Definition
{
	reference_to<ModelViewer>(pw).moveLeft30();
}

void ModelViewer::cb_moveRight30(Address, Address pw)
{
	reference_to<ModelViewer>(pw).moveRight30();
}

void ModelViewer::cb_moveUp30(Address, Address pw)
{
	reference_to<ModelViewer>(pw).moveUp30();
}

void ModelViewer::cb_moveDown30(Address, Address pw)
{
	reference_to<ModelViewer>(pw).moveDown30();
}



int main()
{
	int win_width = 1280;
	int win_height = 960;
	Graph_lib::Point win_tl(100, 100);
	ModelViewer win(win_tl, win_width, win_height, "3D Modeling and Viewing");

	win.redraw();
	return Graph_lib::gui_main();
}
