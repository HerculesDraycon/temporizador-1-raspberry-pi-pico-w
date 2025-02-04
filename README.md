# Tarefa - Temporizador de Semáforo - Raspberry Pi Pico W

# Documentação do Código

## **Descrição Geral**

O código controla três LEDs, sendo capaz de:
- Alternar entre os LEDs acesos, simulando o comportamento de um semáforo.
- Configurar e utilizar o temporizadores integrantes do RP2040.
- Alternar entre estados com a função *callback* implementada no sistema.

## **Bibliotecas Utilizadas**

### **Padrão do C**
- `<stdio.h>`: Manipulação de entrada/saída.

### **Pico SDK**
- `pico/stdlib.h`: Configuração padrão para Raspberry Pi Pico. Pôde apresentar toda a estrutura necessária para que esse código funcionasse corretamente, sem a necessidade de mais bibliotecas de *hardware*

## **Constantes**
- `GREEN_PINO`: Define o pino de saída utilizado pelo LED verde do RGB.
- `BLUE_PINO`: Define o pino de saída utilizado pelo LED azul do RGB.
- `RED_PINO`: Define o pino de saída utilizado pelo LED vermelho do RGB.

## **Tipos de dados criados**
- `TrafficState`: Dados da classe enum criados para definir os estados `RED`, `BLUE` e `GREEN` do semáforo, garantindo uma codificação limpa e sólida para transicionar os estados no callback do temporizador.

## **Funções**

## **1. Callback**
### `bool repeating_timer_callback(struct repeating_timer *t)`
- **Descrição**: É um callback usado pelo temporizador repetitivo do Raspberry Pi Pico W. Ela é chamada automaticamente em intervalos definidos.
- **Parâmetros**:
  - `t`: É um ponteiro para `struct repeating_timer`, que contém as informações necessárias sobre o temporizador.

### **2. Função Principal (`main`)**
- **Descrição**:
  - Configura e inicializa os periféricos.
  - Define o `struct repeating_timer`.
  - Inicializa o timer com intervalo definido.
  - Entra em um loop infinito que:
    1. Mantém o processador em idle enquanto o timer funciona.

## **Fluxo do programa**

- O LED vermelho acende e permanece aceso pelo intervalo de tempo definido no temporizador.
- O LED vermelho apaga, o azul (no lugar do amarelo) acende e permanece aceso pelo intervalo de tempo definido no temporizador.
- O LED azul apaga, o verde acende e permanece aceso pelo intervalo de tempo definido no temporizador.
- O ciclo se reinicia acendendo o LED vermelho novamente e apagando os outros.