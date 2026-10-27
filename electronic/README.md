**OBTER ACESSO AO DISPOSITIVO OLED DIRETO NO BARRAMENTO I2C**
Baixe o github do OLED
https://github.com/armlabs/ssd1306_linux.git && ln -s al ssd1306_linux.git && cd al

Compile tudo dentro da pasta
make

Configuracoes iniciais
./ssd1306_pin -n 1 -I 128x64 // -n -> indica o barramento o -I indica o inicializador
./ssd1306_pin -n 1 -c // -c Clear
./ssd1306_pin -n 1 -r 0
./ssd1306_pin -n 1 -x 1 -y 1
./ssd1306_pin -n 1 -l "Hello World"
