% s = serial('COM7', 'BAUDRATE', 115200);
fopen(s);
flushinput(s);
flushoutput(s);
fwrite(s, uint8(1));

dt = 0.1;%0.5;
kp = 0.348;%0.32;
ti = 1.4;%1.45;
td = 0.35;%0.36;
bv = 40;

fprintf(s, num2str(bv));
fprintf(s, num2str(kp));
fprintf(s, num2str(ti));
fprintf(s, num2str(td));
fprintf(s, num2str(dt));

N=120;
PID = zeros(1, N);
ERROR = zeros(1, N);
DISTANCE = zeros(1, N);
t = zeros(1, N);

  for i=1:N
      flushinput(s);
      
      t(i)= i;
      PIDread = fscanf(s);
      ERRORread = fscanf(s);
      DISTANCEread = fscanf(s);
      
      PID(i) = str2num(PIDread);
      ERROR(i) = str2num(ERRORread);
      DISTANCE(i) = str2num(DISTANCEread);
      
      plot(t, PID, 'r--', t, ERROR,'g--', t, DISTANCE,'b--');
      title('Styrsignal och objektavstånd')
      xlabel('Sampel')
      ylabel('')
      legend('PID', 'Felvärde', 'Avstånd(cm)')
      grid on
      drawnow;
  end