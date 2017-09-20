#include<stdio.h>

#include<graphics.h>
#include<math.h>

void swap(int &x, int &y){
	int k = x;
	x = y;
	y = k;
}

void main(){
	int gd = DETECT, gm = DETECT, x1, x2, y1, y1, dx, dy, p, k;
	float m = 0;
	

	
	printf("enter the starting point x1 & y1 = ");
	scanf("&d&d", &x1, &y1);
	
	printf("enter the starting point x2 & y2 = ");
	scanf("&d&d", &x2, &y2);
	
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	m = (float) (y2 - y1) / (x2 - x1);
	
	initgraph(&gd, &gm, "C:\\TC\BGI");
	cleardevice();
	
	if (fabs(m) > 1){
		swap(x1, y1);
		swap(x2, y2);
		swap(dx, dy);
	}
	
	if (x1 > x2){
		x1 = x2;
		y1 = y2;
	}
	
	p = 2 * dy - dx;
	for(k=0; k<abs(dx); k++){
		if (p < 0){
			p = p + 2* dy;
		}
		else{
			if(m < 0){
				y1--;
			}
			else{
				y1++;
			}
			p = p + (2 * dy) - (2 * dx);
		}
		if(fabs(m) <= 1){
			putpixel(x1++, y1, 15);
		}
		else{
			putpixel(y1, x1++, 15);
		}
	}
	

}
