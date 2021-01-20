https://www.stmicroelectronics.com.cn/content/ccc/resource/technical/document/application_note/group1/8a/da/83/41/88/dd/41/54/DM00560907/files/DM00560907.pdf/jcr:content/translations/en.DM00560907.pdf
https://www.vishay.com/docs/73217/an608a.pdf

%Operating conditions
V_IN = 12*4.2;
I_IN = 40;
f_sw = 47e3;
I_ph = I_IN/1.17;

%%%%Single MOSFET

%MOSFET Driver
V_cc = 12;
I_source = 1.7;
I_sink = 2.3;
R_g = 1;

R_dr_source = V_cc/I_source
R_dr_sink = V_cc/I_sink

%MOSFET Selection CSD19531Q5A, FDMS86368-F085 and NTMFS6H800N
R_g_MOS = [1.5 2.5 1.5];
R_DSon = [5.3e-3 3.7e-3 2.1e-3];
V_gp = [4.1 5.5 4.8];
Q_gd = [6.6e-9 11e-9 16e-9];
Q_rr = [226e-9 49e-9 82e-9];
Q_g = [37e-9 57e-9 85e-9];

%Rise and fall times%

R_tot_HO = R_dr_source + R_g + R_g_MOS
R_tot_LO = R_dr_sink + R_g + R_g_MOS

V_gs = V_cc;
V_ds = V_IN;

t_rise = R_tot_HO .* (Q_gd ./ V_ds) .* (V_ds ./ (V_gs - V_gp))
t_fall = R_tot_LO .* (Q_gd ./ V_ds) .* (V_ds ./ V_gp)

%Power calculation

P_sw = 0.5*V_IN*I_IN*f_sw*(t_rise + t_fall)
P_con = R_DSon * I_ph^2
P_Diode = f_sw*Q_rr*V_IN
P_gate = f_sw * Q_g * V_gs

P_tot = P_sw + P_con + P_Diode + P_gate

P_sum = 12*P_tot

%%%%Two MOSFETs
V_cc = 12;
I_source = 1.7;
I_sink = 2.3;
R_g = 1;

R_dr_source = V_cc/I_source
R_dr_sink = V_cc/I_sink

%MOSFET Selection CSD19531Q5A, FDMS86368-F085 and NTMFS6H800N
R_g_MOS = [1.5 2.5 1.5];
R_DSon = [5.3e-3 3.7e-3 2.1e-3];
V_gp = [4.1 5.5 4.8];
Q_gd = [6.6e-9 11e-9 16e-9];
Q_rr = [226e-9 49e-9 82e-9];
Q_g = [37e-9 57e-9 85e-9];

%Rise and fall times%

R_tot_HO = R_dr_source + R_g + R_g_MOS
R_tot_LO = R_dr_sink + R_g + R_g_MOS

V_gs = V_cc;
V_ds = V_IN;

t_rise = R_tot_HO .* (Q_gd ./ V_ds) .* (V_ds ./ (V_gs - V_gp))
t_fall = R_tot_LO .* (Q_gd ./ V_ds) .* (V_ds ./ V_gp)

%Power calculation

P_sw = 0.5*V_IN*(I_ph/2)*f_sw*(t_rise + t_fall)
P_con = R_DSon * (I_ph/2)^2
P_Diode = f_sw*Q_rr*V_IN
P_gate = f_sw * Q_g * V_gs

P_tot = P_sw + P_con + P_Diode + P_gate

P_sum = 12*P_tot

%%%%Single GaNFET

%GaN Driver
V_cc = 5;
I_source = 1.2;
I_sink = 5;
R_g = 1;

R_dr_source = V_cc/I_source
R_dr_sink = V_cc/I_sink

%GaNFET Selection EPC2206, EPC2022 and EPC2001C
R_g_MOS = [0.3 0.3 0.3];
R_DSon = [1.8e-3 2.4e-3 7e-3];
V_gp = [2 2.4 2.3];
Q_gd = [3e-9 2.4e-9 2e-9];
Q_rr = [0 0 0];
Q_g = [15e-9 13e-9 9e-9];

%Rise and fall times%

R_tot_HO = R_dr_source + R_g + R_g_MOS
R_tot_LO = R_dr_sink + R_g + R_g_MOS

V_gs = V_cc;
V_ds = V_IN;

t_rise = R_tot_HO .* (Q_gd ./ V_ds) .* (V_ds ./ (V_gs - V_gp))
t_fall = R_tot_LO .* (Q_gd ./ V_ds) .* (V_ds ./ V_gp)

%Power calculation

P_sw = 0.5*V_IN*I_IN*f_sw*(t_rise + t_fall)
P_con = R_DSon * I_ph^2
P_Diode = f_sw*Q_rr*V_IN
P_gate = f_sw * Q_g * V_gs

P_tot = P_sw + P_con + P_Diode + P_gate