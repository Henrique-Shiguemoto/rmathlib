#define RMATHLIB_IMPLEMENTATION
#include "rmathlib.h"

// this is a test program

int main(void){
	// Vector and matrix operations
	mat3x3 m = (mat3x3){.elem = {-24.232f, -29.279f, -12.071f, 6.501f, 10.164f, -17.398f, -27.136f, 3.361f, 1.01f}};
	v3 u = {3.4f, -4.5f, 6.7f};
	v3 v = {1.2f, -3.4f, 5.6f};

	v3 r = AddV3(u, v);
	printf("u = {%f, %f, %f}\n", u.x, u.y, u.z);
	printf("v = {%f, %f, %f}\n", v.x, v.y, v.z);
	printf("r = {%f, %f, %f}\n", r.x, r.y, r.z);

	f32 m_det = DetMatrix3x3(m);
	printf("det(m) = %f\n", m_det);

	// Trig operations	
	f32 a = -48261.5f;
	printf("sin(a) = %f\n", Sin32(a));
	printf("cos(a) = %f\n", Cos32(a));
	printf("tg(a)  = %f\n", Tg32(a));

	// Convenient math operations
	f64 x = 33.5;
	printf("sqrt(x) = %lf\n", Sqrt64(x));
	f64 y = -314.1;
	printf("sign(x) = %s\n", Sign(y) == -1 ? "Negative" : "Positive");

	// Random operations
	u32 random_uint32 = RandomU32();
	printf("random_uint32 = %u\n", random_uint32);
	mat4x4 random_mat4x4 = RandomMat4x4();
	printf("random_mat4x4 = {%f, %f, %f, %f,\n", random_mat4x4.elem[0], random_mat4x4.elem[1], random_mat4x4.elem[2], random_mat4x4.elem[3]);
	printf("                 %f, %f, %f, %f,\n", random_mat4x4.elem[4], random_mat4x4.elem[5], random_mat4x4.elem[6], random_mat4x4.elem[7]);
	printf("                 %f, %f, %f, %f,\n", random_mat4x4.elem[8], random_mat4x4.elem[9], random_mat4x4.elem[10], random_mat4x4.elem[11]);
	printf("                 %f, %f, %f, %f}\n", random_mat4x4.elem[12], random_mat4x4.elem[13], random_mat4x4.elem[14], random_mat4x4.elem[15]);

	//Computer Graphics operations
	v2 scaling = {3.308f, -12.505f};
	mat3x3 scaleMatrix = CreateScaleMatrix2D(scaling);
	printf("scaleMatrix = {%f, %f, %f,\n", scaleMatrix.elem[0], scaleMatrix.elem[1], scaleMatrix.elem[2]);
	printf("               %f, %f, %f,\n", scaleMatrix.elem[3], scaleMatrix.elem[4], scaleMatrix.elem[5]);
	printf("               %f, %f, %f}\n", scaleMatrix.elem[6], scaleMatrix.elem[7], scaleMatrix.elem[8]);

	mat4x4 rotationMatrixInY = CreateEulerRotationInYMatrix3D(0.01f);
	printf("rotationMatrixInY = {%f, %f, %f, %f,\n", rotationMatrixInY.elem[0], rotationMatrixInY.elem[1], rotationMatrixInY.elem[2], rotationMatrixInY.elem[3]);
	printf("                 	 %f, %f, %f, %f,\n", rotationMatrixInY.elem[4], rotationMatrixInY.elem[5], rotationMatrixInY.elem[6], rotationMatrixInY.elem[7]);
	printf("                 	 %f, %f, %f, %f,\n", rotationMatrixInY.elem[8], rotationMatrixInY.elem[9], rotationMatrixInY.elem[10], rotationMatrixInY.elem[11]);
	printf("                 	 %f, %f, %f, %f}\n", rotationMatrixInY.elem[12], rotationMatrixInY.elem[13], rotationMatrixInY.elem[14], rotationMatrixInY.elem[15]);

	// Geometry operations
	line3D l1 = {.direction = {-18.913f, -10.717f, 1.189f}, .arbitraryPoint = {27.783f, -20.857f, 24.23f}};
	line3D l2 = {.direction = {-25.673f, 10.673f, -12.49f}, .arbitraryPoint = {17.083f, 26.574f, -19.37f}};
	f32 distance = DistanceBetweenLines3D(l1, l2);
	printf("distance(l1, l2) = %f\n", distance);

	sphere3D sphere = {.center = {1.501f, -15.635f, 19.744f}, .radius = 11.458f};
	f32 volume = VolumeSphere3D(sphere);
	printf("volume(sphere) = %f\n", volume);

	return 0;
}