    #include <glad/glad.h>
    #include <GLFW/glfw3.h>
    #include <iostream>
    #include <engine/node.h>
    #include <engine/scene.h>
    #include <render/render.h>
    #include <engine/effect/testEffect.h>

    // settings
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;
    int main()
    {
        // glfw: initialize and configure
        // ------------------------------
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //uncomment this statement to fix compilation on OS X
    #endif
        // glfw window creation
        // --------------------
        GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT,"LearnOpenGL", NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);
        // glad: load all OpenGL function pointers
        // ---------------------------------------
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }

        // resigner a scene
        chenpi::Scene* pScene = new chenpi::Scene();
        // creat root Node
        chenpi::Node* pRootNode = new chenpi::Node();
        //push effect to Node
        chenpi::Effect* pTestEffect = new chenpi::TestEffect();
        pRootNode->PushEffect(pTestEffect);
        pScene->SetRootNode(pRootNode);

        // render loop
        // -----------
        while (!glfwWindowShouldClose(window))
        {
            pScene->Draw();
            // glfw: swap buffers and poll IO events (keyspressed/released, mouse moved etc.)
            // ---------------------------------------------------
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
        // glfw: terminate, clearing all previously allocated GLFWresources.
        //---------------------------------------------------------------
        glfwTerminate();


        if(pScene) delete pScene;
        return 0;
    }