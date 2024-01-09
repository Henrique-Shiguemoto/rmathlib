#include "rmathlib.h"

#include <iostream>

int main(void){
	// Vector and matrix operations
	rm_mat3f m = {{-24.232f, -29.279f, -12.071f, 6.501f, 10.164f, -17.398f, -27.136f, 3.361f, 1.01f}};
	rm_v3f u = {3.4f, -4.5f, 6.7f};
	rm_v3f v = {1.2f, -3.4f, 5.6f};

	rm_v3f r = rm_add_v3f(u, v);
	std::cout << "u = {" << u.x << ", " << u.y << "," << u.z << "}" << std::endl;
	std::cout << "v = {" << v.x << ", " << v.y << "," << v.z << "}" << std::endl;
	std::cout << "r = {" << r.x << ", " << r.y << "," << r.z << "}" << std::endl;

	float m_det = rm_det_mat3f(m);
	std::cout << "det(m) = " << m_det << std::endl;

	// Trig operations	
	float a = -48261.5f;
	std::cout << "sin(a) = " << rm_sin32(a) << std::endl;
	std::cout << "cos(a) = " << rm_cos32(a) << std::endl;
	std::cout << "tg(a)  = " << rm_tg32(a) << std::endl;

	// Convenient math operations
	double x = 33.5;
	std::cout << "sqrt(x) = " << rm_sqrt64(x) << std::endl;
	double y = -314.1;
	std::cout << "sign(y) = " << (rm_sign(y) == -1 ? "Negative" : "Positive") << std::endl;

	// Random operations
	unsigned int random_uint32 = rm_random_u32();
	std::cout << "random_uint32 = " << random_uint32 << std::endl;
	rm_mat4f random_mat4x4 = rm_random_mat4f();
	std::cout << "random_mat4x4 = {" << random_mat4x4.elem[0]  << ", " << random_mat4x4.elem[1]  << ", " << random_mat4x4.elem[2]  << ", " << random_mat4x4.elem[3]  << ", " << std::endl;
	std::cout << "                {" << random_mat4x4.elem[4]  << ", " << random_mat4x4.elem[5]  << ", " << random_mat4x4.elem[6]  << ", " << random_mat4x4.elem[7]  << ", " << std::endl;
	std::cout << "                {" << random_mat4x4.elem[8]  << ", " << random_mat4x4.elem[9]  << ", " << random_mat4x4.elem[10] << ", " << random_mat4x4.elem[11] << ", " << std::endl;
	std::cout << "                {" << random_mat4x4.elem[12] << ", " << random_mat4x4.elem[13] << ", " << random_mat4x4.elem[14] << ", " << random_mat4x4.elem[15] << "}" << std::endl;

	//Computer Graphics operations
	rm_v2f scaling = {3.308f, -12.505f};
	rm_mat3f scaleMatrix = rm_scaling_2D(scaling);
	std::cout << "scaleMatrix = {" << scaleMatrix.elem[0] << ", " << scaleMatrix.elem[1] << ", " << scaleMatrix.elem[2] << ", " << std::endl;
	std::cout << "              {" << scaleMatrix.elem[3] << ", " << scaleMatrix.elem[4] << ", " << scaleMatrix.elem[5] << ", " << std::endl;
	std::cout << "              {" << scaleMatrix.elem[6] << ", " << scaleMatrix.elem[7] << ", " << scaleMatrix.elem[8] << "} " << std::endl;

	rm_mat4f rotationMatrixInY = rm_euler_rotationX_3D(0.01f);
	std::cout << "rotationMatrixInY = {" << rotationMatrixInY.elem[0]  << ", " << rotationMatrixInY.elem[1]  << ", " << rotationMatrixInY.elem[2]  << ", " << rotationMatrixInY.elem[3] << ", " << std::endl;
	std::cout << "                    {" << rotationMatrixInY.elem[4]  << ", " << rotationMatrixInY.elem[5]  << ", " << rotationMatrixInY.elem[6]  << ", " << rotationMatrixInY.elem[7] << ", " << std::endl;
	std::cout << "                    {" << rotationMatrixInY.elem[8]  << ", " << rotationMatrixInY.elem[9]  << ", " << rotationMatrixInY.elem[10] << ", " << rotationMatrixInY.elem[11] << ", " << std::endl;
	std::cout << "                    {" << rotationMatrixInY.elem[12] << ", " << rotationMatrixInY.elem[13] << ", " << rotationMatrixInY.elem[14] << ", " << rotationMatrixInY.elem[15] << "}" << std::endl;

	// Geometry operations
	rm_line3D l1 = {{-18.913f, -10.717f, 1.189f}, {27.783f, -20.857f, 24.23f}};
	rm_line3D l2 = {{-25.673f, 10.673f, -12.49f}, {17.083f, 26.574f, -19.37f}};
	float distance = rm_distance_lines3D(l1, l2);
	std::cout << "distance(l1, l2) = " << distance << std::endl;

	rm_sphere sphere = {{1.501f, -15.635f, 19.744f}, 11.458f};
	float volume = rm_volume_sphere(sphere);
	std::cout << "volume(sphere) = " << volume << std::endl;

	return 0;
}
