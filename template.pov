                          
#include "colors.inc"    
          
                                        
camera {                                
    sky <0,0,1>                         
    direction <-1,0,0>                  
    right <-16/9,0,0>                    
    location <00,00,700>                
    look_at <0,0,0>                     
    angle 45                            
}                                       
                                        
global_settings { ambient_light White } 
global_settings { max_trace_level 180 } 
                                        
light_source {                          
    <410,20,70>                        
    color White                         
}                                       
                            

light_source {                          
    <-410,520,370>                        
    color White                         
}                                       
                            
                                        
background { color Black }              
  
#declare Surface_Texture = 
         texture { pigment{ color rgbt< 0.75, 0.75, 0.75, 0.75> }  
                   finish { phong 1 reflection 0.00}
                 } // end of texture 

                                      
#declare ppp = array[<<!!--count of points--!!>>]              
{                                       
<<!!--Main Array of points--!!>>
};                               

#declare i = 0;                             
#while(i < <<!!--count of points--!!>>)                       
    #if (vlength(ppp[i] - ppp[i+1])!=0)             
        cylinder{ppp[i],  ppp[i+1], 0.2             
            texture {pigment{color Gray}}         
        }                                           
    #end                                            
    #if (vlength(ppp[i] - ppp[i+2])!=0)             
        cylinder{ppp[i],  ppp[i+2], 0.2             
            texture {pigment{color Gray}}         
        }                                           
    #end                                            
    #if (vlength(ppp[i+1] - ppp[i+2])!=0)           
        cylinder{ppp[i+1],  ppp[i+2], 0.2           
            texture {pigment{color Gray}}         
        }                                           
    #end   
                 
    polygon {4                                      
        ppp[i], ppp[i+1], ppp[i+2] ,ppp[i]          
  	texture { Surface_Texture }}                                               
                                                    
#declare i=i+3;                                     
#end                                                
