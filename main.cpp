#include <murAPI.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int h_green_min=0; 
int s_green_min=92; 
int v_green_min=0; 
int h_green_max=255; 
int s_green_max=255; 
int v_green_max=197; 
int h_red_min=0; 
int s_red_min=0; 
int v_red_min=0; 
int h_red_max=255; 
int s_red_max=255; 
int v_red_max=173; 
int h_yellow_min=0; 
int s_yellow_min=106; 
int v_yellow_min=0; 
int h_yellow_max=255; 
int s_yellow_max=255; 
int v_yellow_max=255;

int findfg(Mat im){
    if (im.empty()){
        cerr << "Image's empty" << endl;
        return -1;
        }
    else{
        
        Mat green = im.clone();
        
        cvtColor(green, green, CV_BGR2HSV);
        
        imshow("gr1", green);
        
        inRange(green, Scalar(h_green_min, s_green_min, v_green_min), Scalar(h_green_max, s_green_max, v_green_max), green);//---
        //double cannyParams = threshold(im, im, 0, 255, CV_THRESH_BINARY_INV + CV_THRESH_OTSU);
        
        imshow("grs", green);
        
        vector <vector <Point>> contours;
        findContours(green, contours, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);
        
        
        
        for (size_t i=0; i<contours.size(); i++){
            vector <Point> hull; //точки контура
            convexHull(contours[i], hull, true);
            approxPolyDP(hull, hull, 7, true); // experimental way!
            
            
            
            //RotatedRect bEllipse = fitEllipse(contours.at(i));
            Rect rect = boundingRect(contours[i]);
            //int x = (int)bEllipse.center.x;
            //int y = (int)bEllipse.center.y;
            int r = (int)rect.width/2;
            //int angle = bEllipse.angle;
            //int size = bEllipse.size.area();*/
            
            double area = contourArea(contours.at(i));
            int areaR = r*r*3.14159;
            
            cout << "areaR green: " << abs(1-(areaR/area)) << " " << area << " " << areaR << endl;
                cout << hull.size() << endl;
           
                
            if ((hull.size()>=8)){
                drawContours(green, contours, i, Scalar(123, 255, 56), 8);
                imshow("gr2", green);
                //circle(red, Point(x, y), 2, Scalar(0, 255, 0), 4);
                return 1;
                }       
        }
        
    
    }
    
    return 0;
}
 
//----------------------------------

int findfr(Mat im){
    if (im.empty()){
        cerr << "Image's empty" << endl;
        return -1;
        }
    else{
        
        Mat red = im.clone();
        
        //cvtColor(im, im, CV_BGR2GRAY);
        
        cvtColor(red, red, CV_BGR2HSV);
        
        imshow("red1", red);

        inRange(red, Scalar(h_red_min, s_red_min, v_red_min), Scalar(h_red_max, s_red_max, v_red_max), red);
        //double cannyParams = threshold(im, im, 0, 255, CV_THRESH_BINARY_INV + CV_THRESH_OTSU);
        
        imshow("reds", red);
        
        vector <vector <Point>> contours;
        findContours(red, contours, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);
        
        for (size_t i=0; i<contours.size(); i++){
            vector <Point> hull; //точки контура
            convexHull(contours[i], hull, true);
            approxPolyDP(hull, hull, 7, true); // experimental way!
            
            
            
            //RotatedRect bEllipse = fitEllipse(contours.at(i));
            Rect rect = boundingRect(contours[i]);
            //int x = (int)bEllipse.center.x;
            //int y = (int)bEllipse.center.y;
            int r = (int)rect.width/2;
            //int angle = bEllipse.angle;
            //int size = bEllipse.size.area();*/
            
            double area = contourArea(contours.at(i));
            int areaR = r*r*3.14159;
            
            cout << "areaR red: " << abs(1-(areaR/area)) << " " << area << " " << areaR << endl;
            cout << hull.size() << endl;
                
           
                
            if ((hull.size()>=8)){
                drawContours(red, contours, i, Scalar(123, 255, 56), 8);
                imshow("red2", red);
                //circle(red, Point(x, y), 2, Scalar(0, 255, 0), 4);
                return 1;
                }
        }
    
    }
    
    return 0;
}
 
//------------------------------


int findfy(Mat im){
    if (im.empty()){
        cerr << "Image's empty" << endl;
        return -1;
        }
    else{
        Mat yellow = im.clone();
        
        //cvtColor(im, im, CV_BGR2GRAY);
        
        cvtColor(yellow, yellow, CV_BGR2HSV);
        
        imshow("y1", yellow);
        
        
        inRange(yellow, Scalar(h_yellow_min, s_yellow_min, v_yellow_min), Scalar(h_yellow_max, s_yellow_max, v_yellow_max), yellow);
        //double cannyParams = threshold(im, im, 0, 255, CV_THRESH_BINARY_INV + CV_THRESH_OTSU);
        
        imshow("yellows", yellow);
        
        vector <vector <Point>> contours;
        findContours(yellow, contours, CV_RETR_TREE, CV_CHAIN_APPROX_NONE);
        
        for (size_t i=0; i<contours.size(); i++){
            vector <Point> hull; //точки контура
            convexHull(contours[i], hull, true);
            approxPolyDP(hull, hull, 7, true); // experimental way!
            
            
            
            //RotatedRect bEllipse = fitEllipse(contours.at(i));
            Rect rect = boundingRect(contours[i]);
            //int x = (int)bEllipse.center.x;
            //int y = (int)bEllipse.center.y;
            int r = (int)rect.width/2;
            //int angle = bEllipse.angle;
            //int size = bEllipse.size.area();*/
            
            double area = contourArea(contours.at(i));
            int areaR = r*r*3.14159;
            
            cout << "areaR yellow: " << abs(1-(areaR/area)) << " " << area << " " << areaR << endl;
            cout << hull.size() << endl;
           
                
            if ((hull.size()>=8)){
                
                drawContours(yellow, contours, i, Scalar(123, 255, 56), 8);
                imshow("y2", yellow);
                //circle(red, Point(x, y), 2, Scalar(0, 255, 0), 4);
                return 1;
                }              
        }
    
    }
    
    return 0;
}
 

int main()
{
    
    //Mat image = imread("C:\\murIDE\\Projects\\Picture\\1.png");
    Mat image = imread("C:/murProjects/Find/red.jpg");
    
    findfr(image);
    
    image = imread("C:/murProjects/Find/green.jpg");
    findfg(image);
    
    image = imread("C:/murProjects/Find/yellow.jpg");
    
    findfy(image);
    
    //Mat w3 = findf(image);
    //imshow("yellow", w3);
    
    waitKey();
       
    return 0;
}
