N=240;
PID = zeros(1, N);
ERROR = zeros(1, N);
DISTANCE = zeros(1, N);
t = zeros(1, N);

  for i=1:N
      flushinput(s);
      
      % Read values from Arduino as a string (PID, error, distance)
      t(i)= i;
      PIDread = fscanf(s);
      ERRORread = fscanf(s);
      DISTANCEread = fscanf(s);
      
      % Convert from string to double
      PID(i) = str2double(PIDread);
      ERROR(i) = str2double(ERRORread);
      DISTANCE(i) = str2double(DISTANCEread);
      
      plot(t, PID, 'g--', t, ERROR,'r--', t, DISTANCE,'b--')
      refline(0, bv);
      title('Styrsignal och objektavst�nd')
      xlabel('Sampel')
      ylabel('')
      legend('Styrsignal', 'Felv�rde(cm)', '�rv�rde(cm)')
      grid on
      drawnow;
  end