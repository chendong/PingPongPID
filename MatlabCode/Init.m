% s = serial('COM7', 'BAUDRATE', 115200);
fopen(s);
flushinput(s);
flushoutput(s);

% Ziegler-Nichols
bv = 40;
kp = 0.6 * 3.2;
ti = 0.5 * 0.9;
td = 0.125 * 0.9;
dt = 0.1;

% Karl Johan Åström and Tore Hägglund
bv = 40;
kp = 0.35 * 3.2;
ti = 0.77 * 0.9;
td = 0.19 * 0.9;
dt = 0.1;

% Ziegler-Nichols after adjustment
bv = 40;
kp = 0.25 * 3.2;
ti = 0.72 * 0.9;
td = 0.21 * 0.9;
dt = 0.1;

% Receiver ready
fwrite(s, uint8(1));

% Transfering parameters to Arduino
fprintf(s, num2str(bv));
fprintf(s, num2str(kp));
fprintf(s, num2str(ti));
fprintf(s, num2str(td));
fprintf(s, num2str(dt));

