//#include "hw3.h"
//
//// implementation of vertexbuffer
//
//// todo: define every member function of vertexbuffer here
//
//
//// implementation of facebuffer
//
//// todo: define every member function of facebuffer here
//
//
//// implementation of vector3
//
//vector3::vector3()
//{
//	v[0] = v[1] = v[2] = 0.0f;
//}
//
//vector3::vector3(const vector4& vec)
//{
//	if (vec.w() != 0.0f)
//	{
//		v[0] = vec.x() / vec.w();
//		v[1] = vec.y() / vec.w();
//		v[2] = vec.z() / vec.w();
//	}
//	else
//	{
//		v[0] = vec.x();
//		v[1] = vec.y();
//		v[2] = vec.z();
//	}
//}
//
//vector3::vector3(float x, float y, float z)
//{
//	// todo: implement here
//}
//
//vector3::vector3(float v[3])
//{
//	// todo: implement here
//}
//
//
//// implementation of vector4
//
//vector4::vector4()
//{
//	v[0] = v[1] = v[2] = v[3] = 0.0f;
//}
//
//vector4::vector4(const vector3& vec)
//{
//	v[0] = vec.x();
//	v[1] = vec.y();
//	v[2] = vec.z();
//	v[3] = 0.0;
//}
//
//vector4::vector4(float x, float y, float z, float w)
//{
//	// todo: implement here
//}
//
//vector4::vector4(float v[4])
//{
//	// todo: implement here
//}
//
//
//// implementation of matrix4x4
//
//matrix4x4::matrix4x4()
//{
//}
//
//matrix4x4::matrix4x4(float _00, float _01, float _02, float _03,
//	float _10, float _11, float _12, float _13,
//	float _20, float _21, float _22, float _23,
//	float _30, float _31, float _32, float _33)
//{
//	rows[0] = vector4(_00, _01, _02, _03);
//	rows[1] = vector4(_10, _11, _12, _13);
//	rows[2] = vector4(_20, _21, _22, _23);
//	rows[3] = vector4(_30, _31, _32, _33);
//}
//
//matrix4x4::matrix4x4(const vector4& row0, const vector4& row1, const vector4& row2, const vector4& row3)
//{
//	rows[0] = row0;
//	rows[1] = row1;
//	rows[2] = row2;
//	rows[3] = row3;
//}
//
//matrix4x4::matrix4x4(float m[16])
//{
//	for (int r = 0; r < 4; r++)
//	{
//		rows[r] = vector4(m[r * 4 + 0], m[r * 4 + 1], m[r * 4 + 2], m[r * 4 + 3]);
//	}
//}
//
//
//// implementation of vector3 operations
//
//std::ostream& operator<<(std::ostream& os, const vector3& v)
//{
//	os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
//	return os;
//}
//
//vector3 operator+(const vector3& v1, const vector3& v2)
//{
//	// todo: implement here
//}
//
//vector3 operator-(const vector3& v1, const vector3& v2)
//{
//	// todo: implement here
//}
//
//vector3 operator*(float k, const vector3& v)
//{
//	// todo: implement here
//}
//
//vector3 operator*(const vector3& v, float k)
//{
//	return vector3(k * v.x(), k * v.y(), k * v.z());
//}
//
//vector3 operator/(const vector3& v, float k)
//{
//	if (k == 0.0f)
//	{
//		return v;
//	}
//	else
//	{
//		return vector3(v.x() / k, v.y() / k, v.z() / k);
//	}
//}
//
//vector3 operator^(const vector3& v1, const vector3& v2)
//{
//	// todo: implement here
//}
//
//float operator%(const vector3& v1, const vector3& v2)
//{
//	// todo: implement here
//}
//
//
//// implementation of vector4 operations
//
//std::ostream& operator<<(std::ostream& os, const vector4& v)
//{
//	os << "(" << v.x() << ", " << v.y() << ", " << v.z() << ", " << v.w() << ")";
//	return os;
//}
//
//vector4 operator+(const vector4& v1, const vector4& v2)
//{
//	// todo: implement here
//}
//
//vector4 operator-(const vector4& v1, const vector4& v2)
//{
//	// todo: implement here
//}
//
//vector4 operator*(float k, const vector4& v)
//{
//	// todo: implement here
//}
//
//vector4 operator*(const vector4& v, float k)
//{
//	return vector4(k * v.x(), k * v.y(), k * v.z(), k * v.w());
//}
//
//vector4 operator/(const vector4& v, float k)
//{
//	if (k == 0.0f)
//	{
//		return v;
//	}
//	else
//	{
//		return vector4(v.x() / k, v.y() / k, v.z() / k, v.w() / k);
//	}
//}
//
//float operator%(const vector4& v1, const vector4& v2)
//{
//	// todo: implement here
//}
//
//
//// implementation of matrix4x4 operations
//
//std::ostream& operator<<(std::ostream& os, const matrix4x4& m)
//{
//	os << "( ";
//	os << "(" << m[0][0] << ", " << m[0][1] << ", " << m[0][2] << ", " << m[0][3] << "), ";
//	os << "(" << m[1][0] << ", " << m[1][1] << ", " << m[1][2] << ", " << m[1][3] << "), ";
//	os << "(" << m[2][0] << ", " << m[2][1] << ", " << m[2][2] << ", " << m[2][3] << "), ";
//	os << "(" << m[3][0] << ", " << m[3][1] << ", " << m[3][2] << ", " << m[3][3] << "), ";
//	os << " )";
//
//	return os;
//}
//
//matrix4x4 operator+(const matrix4x4& m1, const matrix4x4& m2)
//{
//	// todo: implement here
//}
//
//matrix4x4 operator-(const matrix4x4& m1, const matrix4x4& m2)
//{
//	// todo: implement here
//}
//
//matrix4x4 operator*(const matrix4x4& m1, const matrix4x4& m2)
//{
//	// todo: implement here
//}
//
//vector4 operator*(const matrix4x4& m, const vector4& v)
//{
//	float w[4];
//
//	for (int r = 0; r < 4; r++)
//	{
//		w[r] = vector4(m[r][0], m[r][1], m[r][2], m[r][3]) % v;
//	}
//
//	return vector4(w);
//}
//
//
//// some helper functions for vector3 and vector4
//
//vector3 vector3_from_vertex(const vertex& vertex)
//{
//	return vector3(vertex.x, vertex.y, vertex.z);
//}
//
//vector4 vector4_from_vertex(const vertex& vertex)
//{
//	return vector4(vertex.x, vertex.y, vertex.z, 1.0f);
//}
//
//float norm(const vector3& v)
//{
//	return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
//}
//
//float norm(const vector4& v)
//{
//	return sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + v[3] * v[3]);
//}
//
//vector3 normalize(const vector3& v)
//{
//	vector3 u(v);
//	float s = 1.0f / norm(v);
//	return s * u;
//}
//
//vector4 normalize(const vector4& v)
//{
//	vector4 u(v);
//	float s = 1.0f / norm(v);
//	return s * u;
//}
//
//
//// implementation of helper functions for matrix4x4
//
//matrix4x4 matrix_identity()
//{
//	return matrix4x4(
//		1, 0, 0, 0,
//		0, 1, 0, 0,
//		0, 0, 1, 0,
//		0, 0, 0, 1
//	);
//}
//
//matrix4x4 matrix_translation(float tx, float ty, float tz)
//{
//	return matrix4x4(
//		1, 0, 0, tx,
//		0, 1, 0, ty,
//		0, 0, 1, tz,
//		0, 0, 0, 1
//	);
//}
//
//// https://en.wikipedia.org/wiki/rotation_matrix#general_rotations
//matrix4x4 matrix_rotation(const vector3& axis, float angle)
//{
//	vector3 u = normalize(axis);
//	float ux = u.x();
//	float uy = u.y();
//	float uz = u.z();
//
//	float cos_a = cosf(angle);
//	float sin_a = sinf(angle);
//
//	float _00 = cos_a + ux * ux * (1 - cos_a);
//	float _01 = ux * uy * (1 - cos_a) - uz * sin_a;
//	float _02 = ux * uy * (1 - cos_a) + uy * sin_a;
//	float _03 = 0.0f;
//
//	float _10 = uy * ux * (1 - cos_a) + uz * sin_a;
//	float _11 = cos_a + uy * uy * (1 - cos_a);
//	float _12 = uy * uz * (1 - cos_a) - ux * sin_a;
//	float _13 = 0.0f;
//
//	float _20 = uz * ux * (1 - cos_a) - uy * sin_a;
//	float _21 = uz * uy * (1 - cos_a) + ux * sin_a;
//	float _22 = cos_a + uz * uz * (1 - cos_a);
//	float _23 = 0.0f;
//
//	float _30 = 0.0f;
//	float _31 = 0.0f;
//	float _32 = 0.0f;
//	float _33 = 1.0f;
//
//	return matrix4x4(
//		_00, _01, _02, _03,
//		_10, _11, _12, _13,
//		_20, _21, _22, _23,
//		_30, _31, _32, _33
//	);
//}
//
//// http://www.codinglabs.net/article_world_view_projection_matrix.aspx
//matrix4x4 matrix_perspective(float fovy, float aspect_ratio, float z_near, float z_far)
//{
//	if (fovy == 0.0f || aspect_ratio == 0.0f || z_near == z_far)
//	{
//		return matrix_identity();
//	}
//
//	float fovx = 2.0f * atanf(tanf(fovy * 0.5f) * aspect_ratio);
//
//	float _00 = 1.0f / tanf(fovx / 2.0f);
//	float _01 = 0.0f;
//	float _02 = 0.0f;
//	float _03 = 0.0f;
//
//	float _10 = 0.0f;
//	float _11 = 1.0f / tanf(fovy / 2.0f);
//	float _12 = 0.0f;
//	float _13 = 0.0f;
//
//	float _20 = 0.0f;
//	float _21 = 0.0f;
//	float _22 = -(z_far + z_near) / (z_far - z_near);
//	float _23 = -2.0f * z_near * z_far / (z_far - z_near);
//
//	float _30 = 0.0f;
//	float _31 = 0.0f;
//	float _32 = -1.0f;
//	float _33 = 0.0f;
//
//	return matrix4x4(
//		_00, _01, _02, _03,
//		_10, _11, _12, _13,
//		_20, _21, _22, _23,
//		_30, _31, _32, _33
//	);
//}
//
//// https://www.scratchapixel.com/lessons/mathematics-physics-for-computer-graphics/lookat-function
//matrix4x4 matrix_lookat(const vector3& eye, const vector3& at, const vector3& up)
//{
//	vector3 n = normalize(eye - at);
//	vector3 u = normalize(normalize(up) ^ n);
//	vector3 v = normalize(n ^ u);
//
//	float _00 = u.x();
//	float _01 = u.y();
//	float _02 = u.z();
//	float _03 = -(eye % u);
//
//	float _10 = v.x();
//	float _11 = v.y();
//	float _12 = v.z();
//	float _13 = -(eye % v);
//
//	float _20 = n.x();
//	float _21 = n.y();
//	float _22 = n.z();
//	float _23 = -(eye % n);
//
//	float _30 = 0.0f;
//	float _31 = 0.0f;
//	float _32 = 0.0f;
//	float _33 = 1.0f;
//
//	return matrix4x4(
//		_00, _01, _02, _03,
//		_10, _11, _12, _13,
//		_20, _21, _22, _23,
//		_30, _31, _32, _33
//	);
//}
//
//const float pi = 3.141592f;
//
//float degree_from_radian(float rad)
//{
//	return rad * 180.0f / pi;
//}
//
//float radian_from_degree(float deg)
//{
//	// todo: implement here
//}
//
