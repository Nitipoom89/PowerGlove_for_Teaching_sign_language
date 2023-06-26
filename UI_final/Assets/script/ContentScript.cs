using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ContentScript : MonoBehaviour
{
    public GameObject RightHand;
    public GameObject lesson;
    public GameObject tutorail;
    public GameObject color;
    public GameObject blue;
    public GameObject pink;
    public GameObject yellow;
    public GameObject number;
    public GameObject num0;
    public GameObject num1;
    public GameObject num2;
    public GameObject num3;
    public GameObject num4;
    public GameObject num5;
    public GameObject num6;
    public GameObject num7;
    public GameObject num8;
    public GameObject num9;
    public GameObject num10;
    public GameObject correct;
    public GameObject wrong;

    
    // Start is called before the first frame update
    void Start()
    {
        //RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        RightHand.transform.localPosition = new Vector3 (-17.0f,24.3f,-34.4f);    //HIDE
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_tutorail()
    {
        RightHand.transform.localPosition = new Vector3 (-17.0f,24.3f,-34.4f);    //HIDE
        lesson.SetActive(false);
        tutorail.SetActive(true);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_Nummode_manunum()
    {
        RightHand.transform.localPosition = new Vector3 (-17.0f,24.3f,-34.4f);    //HIDE
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(true);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_colormode()
    {
        RightHand.transform.localPosition = new Vector3 (-17.0f,24.3f,-34.4f);    //HIDE
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(true);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_blue()
    {
        RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(true);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }
    
    public void Button_pink()
    {
        RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(true);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_yellow()
    {
        RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(true);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_homemanu()
    {
        RightHand.transform.localPosition = new Vector3 (-17.0f,24.3f,-34.4f);    //HIDE
        lesson.SetActive(true);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    
    public void Button_num0()
    {
        RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(true);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_num1()
    {
        RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(true);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_num2()
    {
        RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(true);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_num3()
    {
        RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(true);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_num4()
    {
        RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(true);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_num5()
    {
        RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(true);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_num6()
    {
        RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(true);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_num7()
    {
        RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(true);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }
    public void Button_num8()
    {
        RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(true);
        num9.SetActive(false);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_num9()
    {
        RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(true);
        num10.SetActive(false);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_num10()
    {
       RightHand.transform.localPosition = new Vector3 (-13.93f,23.29f,10.5f);     //SHOW
        lesson.SetActive(false);
        tutorail.SetActive(false);
        color.SetActive(false);
        blue.SetActive(false);
        pink.SetActive(false);
        yellow.SetActive(false);
        number.SetActive(false);
        num0.SetActive(false);
        num1.SetActive(false);
        num2.SetActive(false);
        num3.SetActive(false);
        num4.SetActive(false);
        num5.SetActive(false);
        num6.SetActive(false);
        num7.SetActive(false);
        num8.SetActive(false);
        num9.SetActive(false);
        num10.SetActive(true);
        correct.SetActive(false);
        wrong.SetActive(false);
        
    }

    public void Button_repeat()
    {
        correct.SetActive(false);
        wrong.SetActive(false);
    }
}
