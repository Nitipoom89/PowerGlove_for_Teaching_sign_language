using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneScript : MonoBehaviour
{
    public void loadScene (string namescene) {
        SceneManager.LoadScene(namescene);
    }

    public void Quitgame () {
        Application.Quit();
    }
    
}
