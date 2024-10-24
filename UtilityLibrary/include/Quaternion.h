#pragma once

#include "Vector3.h"
#include "Utilities.h" 

class Quaternion {
public:
    float w; ///< Parte escalar del cuaterni�n.
    float x; ///< Parte vectorial en X del cuaterni�n.
    float y; ///< Parte vectorial en Y del cuaterni�n.
    float z; ///< Parte vectorial en Z del cuaterni�n.

    /**
     * @brief Constructor por defecto que inicializa los valores de w, x, y, z a 0.
     */
    Quaternion() : w(0), x(0), y(0), z(0) {}

    /**
     * @brief Constructor parametrizado que inicializa el cuaterni�n con los valores proporcionados.
     * @param w Valor de la parte escalar.
     * @param x Valor de la parte vectorial X.
     * @param y Valor de la parte vectorial Y.
     * @param z Valor de la parte vectorial Z.
     */
    Quaternion(float wVal, float xVal, float yVal, float zVal) : w(wVal), x(xVal), y(yVal), z(zVal) {}

    /**
     * @brief Constructor que inicializa un cuaterni�n a partir de un �ngulo y un eje de rotaci�n dado como Vector3.
     * @param axis Vector que define el eje de rotaci�n (debe estar normalizado).
     * @param angle �ngulo de rotaci�n en radianes.
     */
    Quaternion(const Vector3& axis, float angle) {
        float 
        halfAngle = angle * 0.5f;
        float 
        sinHalfAngle = sin(halfAngle);
        w = cos(halfAngle);
        x = axis.x * sinHalfAngle;
        y = axis.y * sinHalfAngle;
        z = axis.z * sinHalfAngle;
    }

    /**
     * @brief Sobrecarga del operador + para sumar dos cuaterniones.
     * @param other El cuaterni�n a sumar.
     * @return El cuaterni�n resultante.
     */
    Quaternion operator+(const Quaternion& other) const {
        return Quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
    }

    /**
     * @brief Sobrecarga del operador * para multiplicar un cuaterni�n por un escalar.
     * @param scalar El valor escalar.
     * @return El cuaterni�n escalado.
     */
    Quaternion operator*(float scalar) const {
        return Quaternion(w * scalar, x * scalar, y * scalar, z * scalar);
    }

    /**
     * @brief Sobrecarga del operador * para multiplicar dos cuaterniones.
     * @param other El cuaterni�n a multiplicar.
     * @return El cuaterni�n resultante de la multiplicaci�n.
     */
    Quaternion operator*(const Quaternion& other) const {
        return Quaternion(
            w * other.w - x * other.x - y * other.y - z * other.z,
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w
        );
    }

    /**
     * @brief Calcula la magnitud del cuaterni�n.
     * @return La magnitud del cuaterni�n.
     */
    float 
    magnitude() const {
        return sqrt(w * w + x * x + y * y + z * z);
    }

    /**
     * @brief Normaliza el cuaterni�n, devolviendo un cuaterni�n de magnitud 1.
     * @return El cuaterni�n normalizado.
     */
    Quaternion normalize() const {
        float 
        mag = magnitude();
        if (mag == 0) {
            return Quaternion(0, 0, 0, 0); // Devuelve un cuaterni�n nulo si la magnitud es 0.
        }
        return Quaternion(w / mag, x / mag, y / mag, z / mag);
    }

    /**
     * @brief Devuelve el conjugado del cuaterni�n.
     * @return El cuaterni�n conjugado.
     */
    Quaternion conjugate() const {
        return Quaternion(w, -x, -y, -z);
    }

    /**
     * @brief Devuelve el cuaterni�n inverso.
     * @return El cuaterni�n inverso.
     */
    Quaternion inverse() const {
        float 
        magSquared = w * w + x * x + y * y + z * z;
        if (magSquared == 0) {
            return Quaternion(0, 0, 0, 0); // Devuelve un cuaterni�n nulo si la magnitud es 0.
        }
        return conjugate() * (1.0f / magSquared);
    }

    /**
     * @brief Rota un vector 3D utilizando el cuaterni�n.
     * @param v El vector a rotar.
     * @return El vector rotado.
     */
    Vector3 rotate(const Vector3& v) const {
        Quaternion qv(0, v.x, v.y, v.z);
        Quaternion result = (*this) * qv * this->inverse();
        return Vector3(result.x, result.y, result.z);
    }

    /**
     * @brief Devuelve un puntero a los componentes del cuaterni�n.
     * @return Un puntero a los valores w, x, y, z.
     */
    float* 
    data() {
        return &w;
    }

    /**
     * @brief Devuelve un puntero constante a los componentes del cuaterni�n.
     * @return Un puntero constante a los valores w, x, y, z.
     */
    const 
    float* 
    data() const {
        return &w;
    }
};

