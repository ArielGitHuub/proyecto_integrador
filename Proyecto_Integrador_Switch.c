#include <stdio.h>

int main(void) {
    int categoria;
    int cantidad_gerentes = 0, cantidad_horarios = 0, cantidad_comision = 0;
    float total_gerentes = 0, total_horarios = 0, total_comision = 0, total_empresa = 0;
    char respuesta;

    do {
        printf("Tipos de Trabajadores:\n1. Gerente\n2. Con Horario\n3. A Comisión\n");
        printf("Ingrese la categoría del empleado: ");
        scanf("%d", &categoria);

        switch (categoria) {
            case 1: {
                total_gerentes = total_gerentes + 1380.57;
                cantidad_gerentes = cantidad_gerentes + 1;
                break;
            }
            case 2: {
                float salario_base_horario = 560.84;
                int horas_trabajadas;

                printf("Ingrese las horas trabajadas por el empleado: ");
                scanf("%d", &horas_trabajadas);

                total_horarios += (horas_trabajadas <= 40) ? salario_base_horario : salario_base_horario + 1.5 * (horas_trabajadas - 40);

                cantidad_horarios = cantidad_horarios + 1;
                break;
            }
            case 3: {
                float salario_base_comision = 425.99;
                float ventas;

                printf("Ingrese las ventas que realizó el empleado: ");
                scanf("%f", &ventas);

                float salario_comision = salario_base_comision + 0.046 * ventas;

                total_comision = total_comision + salario_comision;
                cantidad_comision = cantidad_comision + 1;
                break;
            }
            default:
                printf("Categoría no válida. Por favor, ingrese 1, 2 o 3.\n");
                continue;
        }

        do {
            printf("¿Desea calcular el salario de otro empleado? (S para Sí, N para No): ");
            scanf(" %c", &respuesta);

            if (respuesta == 'S' || respuesta == 's' || respuesta == 'N' || respuesta == 'n') {
                break;
            } else {
                printf("Respuesta no válida.\n ");
            }
        } while (1);

    } while (respuesta == 'S' || respuesta == 's');

    total_empresa = total_gerentes + total_horarios + total_comision;

    printf("\nResumen de nómina:\n");
    printf("Gerentes: %d empleado(s), Monto total: $%.2f, Porcentaje: %.2f%%\n", cantidad_gerentes, total_gerentes, (total_gerentes / total_empresa) * 100);
    printf("Trabajadores Horarios: %d empleado(s), Monto total: $%.2f, Porcentaje: %.2f%%\n", cantidad_horarios, total_horarios, (total_horarios / total_empresa) * 100);
    printf("Trabajadores Comisión: %d empleado(s), Monto total: $%.2f, Porcentaje: %.2f%%\n", cantidad_comision, total_comision, (total_comision / total_empresa) * 100);
    printf("Monto total de la empresa a pagar en el mes: $%.2f\n", total_empresa);

    return 0;
}