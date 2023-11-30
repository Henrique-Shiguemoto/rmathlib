#define RMATHLIB_IMPLEMENTATION
#include "rmathlib.h"

#include <stdio.h>

// this is a test program

int main(void){
	// Vector and matrix operations
	rm_mat3f m = (rm_mat3f){.elem = {-24.232f, -29.279f, -12.071f, 6.501f, 10.164f, -17.398f, -27.136f, 3.361f, 1.01f}};
	rm_v3f u = {3.4f, -4.5f, 6.7f};
	rm_v3f v = {1.2f, -3.4f, 5.6f};

	rm_v3f r = rm_add_v3f(u, v);
	printf("u = {%f, %f, %f}\n", u.x, u.y, u.z);
	printf("v = {%f, %f, %f}\n", v.x, v.y, v.z);
	printf("r = {%f, %f, %f}\n", r.x, r.y, r.z);

	float m_det = rm_det_mat3f(m);
	printf("det(m) = %f\n", m_det);

	// Trig operations	
	float a = -48261.5f;
	printf("sin(a) = %f\n", rm_sin32(a));
	printf("cos(a) = %f\n", rm_cos32(a));
	printf("tg(a)  = %f\n", rm_tg32(a));

	// Convenient math operations
	double x = 33.5;
	printf("sqrt(x) = %lf\n", rm_sqrt64(x));
	double y = -314.1;
	printf("sign(x) = %s\n", rm_sign(y) == -1 ? "Negative" : "Positive");

	// Random operations
	unsigned int random_uint32 = rm_random_u32();
	printf("random_uint32 = %u\n", random_uint32);
	rm_mat4f random_mat4x4 = rm_random_mat4f();
	printf("random_mat4x4 = {%f, %f, %f, %f,\n", random_mat4x4.elem[0], random_mat4x4.elem[1], random_mat4x4.elem[2], random_mat4x4.elem[3]);
	printf("                 %f, %f, %f, %f,\n", random_mat4x4.elem[4], random_mat4x4.elem[5], random_mat4x4.elem[6], random_mat4x4.elem[7]);
	printf("                 %f, %f, %f, %f,\n", random_mat4x4.elem[8], random_mat4x4.elem[9], random_mat4x4.elem[10], random_mat4x4.elem[11]);
	printf("                 %f, %f, %f, %f}\n", random_mat4x4.elem[12], random_mat4x4.elem[13], random_mat4x4.elem[14], random_mat4x4.elem[15]);

	//Computer Graphics operations
	rm_v2f scaling = {3.308f, -12.505f};
	rm_mat3f scaleMatrix = rm_scaling_2D(scaling);
	printf("scaleMatrix = {%f, %f, %f,\n", scaleMatrix.elem[0], scaleMatrix.elem[1], scaleMatrix.elem[2]);
	printf("               %f, %f, %f,\n", scaleMatrix.elem[3], scaleMatrix.elem[4], scaleMatrix.elem[5]);
	printf("               %f, %f, %f}\n", scaleMatrix.elem[6], scaleMatrix.elem[7], scaleMatrix.elem[8]);

	rm_mat4f rotationMatrixInY = rm_euler_rotationX_3D(0.01f);
	printf("rotationMatrixInY = {%f, %f, %f, %f,\n", rotationMatrixInY.elem[0], rotationMatrixInY.elem[1], rotationMatrixInY.elem[2], rotationMatrixInY.elem[3]);
	printf("                 	 %f, %f, %f, %f,\n", rotationMatrixInY.elem[4], rotationMatrixInY.elem[5], rotationMatrixInY.elem[6], rotationMatrixInY.elem[7]);
	printf("                 	 %f, %f, %f, %f,\n", rotationMatrixInY.elem[8], rotationMatrixInY.elem[9], rotationMatrixInY.elem[10], rotationMatrixInY.elem[11]);
	printf("                 	 %f, %f, %f, %f}\n", rotationMatrixInY.elem[12], rotationMatrixInY.elem[13], rotationMatrixInY.elem[14], rotationMatrixInY.elem[15]);

	// Geometry operations
	rm_line3D l1 = {.direction = {-18.913f, -10.717f, 1.189f}, .point = {27.783f, -20.857f, 24.23f}};
	rm_line3D l2 = {.direction = {-25.673f, 10.673f, -12.49f}, .point = {17.083f, 26.574f, -19.37f}};
	float distance = rm_distance_lines3D(l1, l2);
	printf("distance(l1, l2) = %f\n", distance);

	rm_sphere sphere = {.center = {1.501f, -15.635f, 19.744f}, .radius = 11.458f};
	float volume = rm_volume_sphere(sphere);
	printf("volume(sphere) = %f\n", volume);

	return 0;
}
