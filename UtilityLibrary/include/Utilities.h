#pragma once

/**
 * @brief Función para calcular la raíz cuadrada de un valor positivo utilizando el método de aproximación de Newton.
 *
 * @param value Valor flotante cuyo valor de raíz cuadrada se desea calcular.
 * @return float Raíz cuadrada aproximada del valor. Si el valor es negativo, retorna 0.
 */
inline float sqrt(float value) {
    if (value < 0) {
        return 0;  // Si el valor es negativo, retorna 0
    }

    float x = value; // Valor inicial
    float y = 1.0f;  // Aproximación inicial
    float epsilon = 0.00001f; // Precisión deseada para el cálculo

    // Aproximación de Newton-Raphson para encontrar la raíz cuadrada
    while (x - y > epsilon) {
        x = (x + y) / 2.0f;
        y = value / x;
    }

    return x; // Retorna el valor aproximado de la raíz cuadrada
}
