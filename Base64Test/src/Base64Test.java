import java.io.UnsupportedEncodingException;  
import sun.misc.*;  

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Base64Test {

	public static void main(String[] args) {
		//String str = "{\"tasks\":[{\"id\":1024684,\"url\":\"www.pvtc.edu.cn\",\"param\":\"\"}, {\"id\":1024726,\"url\":\"www.dxalga.gov.cn\","+
		//"\"param\":\"system\"}, {\"id\":1023629,\"url\":\"xuebao.cau.edu.cn\",\"param\":\"manager system\"}]}"; 

		Base64Test mb64=new Base64Test();
		String str=mb64.readTxtFile("task.json");
	    	String encodeBase64 = mb64.getBase64(str);  
	    	//System.out.println(encodeBase64);
	    	mb64.saveToFile(encodeBase64);
	}

    public static String getBase64(String str) {  
        byte[] b = null;  
        String s = null;  
        try {  
            b = str.getBytes("utf-8");  
        } catch (UnsupportedEncodingException e) {  
            e.printStackTrace();  
        }  
        if (b != null) {  
            s = new BASE64Encoder().encode(b);  
        }  
        return s;  
    }  
  
    public static String getFromBase64(String s) {  
        byte[] b = null;  
        String result = null;  
        if (s != null) {  
            BASE64Decoder decoder = new BASE64Decoder();  
            try {  
                b = decoder.decodeBuffer(s);  
                result = new String(b, "utf-8");  
            } catch (Exception e) {  
                e.printStackTrace();  
            }  
        }  
        return result;  
    }  
   
	public static void saveToFile(String content) {
		FileOutputStream fop = null;
		File file;

		try {
			file = new File("busi.conf");
			fop = new FileOutputStream(file);

			// if file doesnt exists, then create it
			if (!file.exists()) {
				file.createNewFile();
			}

			// get the content in bytes
			byte[] contentInBytes = content.getBytes();

			fop.write(contentInBytes);
			fop.flush();
			fop.close();

			System.out.println("Done");

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (fop != null) {
					fop.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

    public static String readTxtFile(String filePath){
	String ret="";
        try {
                String encoding="utf-8";
                File file=new File(filePath);
                if(file.isFile() && file.exists()){ 
                    InputStreamReader read = new InputStreamReader(
                    new FileInputStream(file),encoding);
                    BufferedReader bufferedReader = new BufferedReader(read);

                    String lineTxt = null;
                    while((lineTxt = bufferedReader.readLine()) != null){
                       ret+=lineTxt;
                    }

                    read.close();
        }else{
            System.out.println("找不到指定的文件");
        }
        } catch (Exception e) {
            System.out.println("读取文件内容出错");
            e.printStackTrace();
        }
	return ret;
    }
}
