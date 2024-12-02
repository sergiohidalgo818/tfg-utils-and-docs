import numpy as np



def detect_points(data:np.ndarray)->tuple:

    x_data:np.ndarray = data[0]
    time_data:np.ndarray = data[1]

    sign_list:list = []
    d_location:list = []
    
    sign_flag = False
    for i in  range (x_data.size - 1): # change to start on 1
        dx = 1
        t_act = time_data[i]
        x_act = x_data[i]
        
        t_next = time_data[i+1]
        x_next = x_data[i+1]
        t_diff = t_next - t_act
            
        dx = round(x_next - x_act)/t_diff

        t_act = t_next
        x_act = x_next
            

        if sign_flag:
            dx_sign = np.sign([dx])[0]
            sign_list.append(-dx_sign)
            sign_flag = False
        
        if dx == 0:
            sign_flag = True
            d_location.append(i)
        
    return (d_location, sign_list)