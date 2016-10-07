import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;


public class JaccardSimilarity{

    public JaccardSimilarity() {
    }
    
    public boolean codeFilter(int code) {
        if ((code < 19968 || code > 40869) 
		&& !(code >= '0' && code <= '9') 
		&& !(code >= 'a' && code <= 'z') 
		&& !(code >= 'A' && code <= 'Z')) {
            return false;
        }
        return true;
    }

    public double CalculateTextSim(String content, String compareContent) {
        if(null == content || null == compareContent)
            return 0.0;
        Map<String, Integer> cntMap = new HashMap<String, Integer>();
        Set<String> cntSet = new HashSet<String>();
        Map<String, Integer> cmpCntMap = new HashMap<String, Integer>();
        Set<String> cmpCntSet = new HashSet<String>();
        
	for (int i = 0; i != content.length(); i++) {
            int k = 0;
            if (codeFilter(content.codePointAt(i))) {
                if (cntMap.containsKey("" + content.charAt(i))) {
                    Integer count = cntMap.get("" + content.charAt(i));
                    count = count + 1;
                    cntMap.put("" + content.charAt(i), count);
                    k = count;
                } else {
                    cntMap.put("" + content.charAt(i), new Integer(1));
                    k = 1;
                }
                String tmpString = content.charAt(i) + "" + k;
                cntSet.add(tmpString);
            }
        }

        for (int i = 0; i != compareContent.length(); i++) {
            int k = 0;
            if (codeFilter(compareContent.codePointAt(i))) {
                if (cmpCntMap.containsKey("" + compareContent.charAt(i))) {
                    Integer count = cmpCntMap.get("" + compareContent.charAt(i));
                    count = count + 1;
                    cmpCntMap.put("" + compareContent.charAt(i), count);
                    k = count;
                } else {
                    cmpCntMap.put("" + compareContent.charAt(i), new Integer(1));
                    k = 1;
                }

                String tmpString = compareContent.charAt(i) + "" + k;
                cmpCntSet.add(tmpString);
            }
        }

        Set<String> tmpSet = new HashSet<String>();
        tmpSet.addAll(cntSet);
        cntSet.retainAll(cmpCntSet);
        double intCount = cntSet.size();

        tmpSet.addAll(cmpCntSet);


        if (tmpSet.size() == 0)
            return 0;
        double uniCount = tmpSet.size();

	//System.out.println("intCount="+intCount+","+"uniCount="+uniCount);
        return intCount / uniCount;
    }

}


