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