#pragma once

/**
 * @brief Funci�n para calcular la ra�z cuadrada de un valor positivo utilizando el m�todo de aproximaci�n de Newton.
 *
 * @param value Valor flotante cuyo valor de ra�z cuadrada se desea calcular.
 * @return float Ra�z cuadrada aproximada del valor. Si el valor es negativo, retorna 0.
 */
inline float sqrt(float value) {
    if (value < 0) {
        return 0;  // Si el valor es negativo, retorna 0
    }

    float x = value; // Valor inicial
    float y = 1.0f;  // Aproximaci�n inicial
    float epsilon = 0.00001f; // Precisi�n deseada para el c�lculo

    // Aproximaci�n de Newton-Raphson para encontrar la ra�z cuadrada
    while (x - y > epsilon) {
        x = (x + y) / 2.0f;
        y = value / x;
    }

    return x; // Retorna el valor aproximado de la ra�z cuadrada
}
