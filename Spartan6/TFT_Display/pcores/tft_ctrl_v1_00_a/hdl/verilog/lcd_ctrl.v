module lcd_ctrl(clk,rst,IsSta,IsReg,LCD_CS,LCD_RS,LCD_WR,LCD_RD,DB_BUS,M_DB,IsBusy,DELAY);

input  clk;
input  rst;
input  IsSta;
input  IsReg;
output reg LCD_CS;
output reg LCD_RS;
output reg LCD_WR;
output reg LCD_RD;
output reg [15 : 0 ]DB_BUS;
input  [15 : 0 ]M_DB;
output reg IsBusy;
input  [ 7:0 ]DELAY;



reg [ 2:0 ] s;
reg [ 7:0 ] C1;

always @( posedge clk )begin 
	if(rst) begin C1 <= 0; s <= 0; LCD_CS <= 1'b1; LCD_RS <= 1'b1; LCD_WR <= 1'b1; LCD_RD <= 1'b1; IsBusy <= 1'b1; end 
	else begin // write reg 
			case(s)
				0:
				begin
					LCD_CS <= 1'b0;IsBusy<=1'b0; 
					if(IsSta)begin s <= s + 1'b1;IsBusy <= 1'b1; end
				end
				1: 
				begin 
					if(IsReg==1) LCD_RS <= 1'b0;else LCD_RS <= 1'b1;
					s <= s + 1'b1; 
				end 
				2: 
				begin 
					DB_BUS <= M_DB[ 15:0 ];s <= s + 1'b1; 
				end 
				3: 
				begin 
					LCD_WR <= 1'b0; 
					if( C1<DELAY ) C1 <= C1 + 1'b1; else 
					begin C1 <= 0; s <= s + 1'b1; end 
				end 
				4: 
				begin 
					LCD_WR <= 1'b1; 
					if( C1<DELAY ) C1 <= C1 + 1'b1; else 
					begin C1 <= 0; s <=0; end 
				end 
				default:
				 begin C1 <= 0; s <= 0; LCD_CS <= 1'b1; LCD_RS <= 1'b1; LCD_WR <= 1'b1; LCD_RD <= 1'b1;  IsBusy <= 1'b1; end 
			endcase
		end
end

endmodule