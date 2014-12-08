//-----------------------------------------------------------------------------
// system_tft_ctrl_0_wrapper.v
//-----------------------------------------------------------------------------

module system_tft_ctrl_0_wrapper
  (
    FSL_Clk,
    FSL_Rst,
    FSL_S_Clk,
    FSL_S_Read,
    FSL_S_Data,
    FSL_S_Control,
    FSL_S_Exists,
    LCD_CS,
    LCD_RS,
    LCD_WR,
    LCD_RD,
    DB_BUS
  );
  input FSL_Clk;
  input FSL_Rst;
  input FSL_S_Clk;
  output FSL_S_Read;
  input [0:31] FSL_S_Data;
  input FSL_S_Control;
  input FSL_S_Exists;
  output LCD_CS;
  output LCD_RS;
  output LCD_WR;
  output LCD_RD;
  output [15:0] DB_BUS;

  tft_ctrl
    tft_ctrl_0 (
      .FSL_Clk ( FSL_Clk ),
      .FSL_Rst ( FSL_Rst ),
      .FSL_S_Clk ( FSL_S_Clk ),
      .FSL_S_Read ( FSL_S_Read ),
      .FSL_S_Data ( FSL_S_Data ),
      .FSL_S_Control ( FSL_S_Control ),
      .FSL_S_Exists ( FSL_S_Exists ),
      .LCD_CS ( LCD_CS ),
      .LCD_RS ( LCD_RS ),
      .LCD_WR ( LCD_WR ),
      .LCD_RD ( LCD_RD ),
      .DB_BUS ( DB_BUS )
    );

endmodule

