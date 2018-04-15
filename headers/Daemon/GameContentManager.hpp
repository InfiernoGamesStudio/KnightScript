/**
 * MIT License
 *
 * Copyright (c) 2018 InfiernoGamesStudio
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **/

#ifndef _DAEMON_GAME_CONTENT_MANAGER_HPP_
#define _DAEMON_GAME_CONTENT_MANAGER_HPP_

  #include "GameManager.hpp"

  namespace Daemon {

    enum EAssetTypes {

      TEXTURE,
      SHADER,
      MESH,

    };

    struct GameContentManager {

      unsigned int model_count;
      GameManager< struct GameTexture > textures;
      GameManager< struct GameShader > shaders;
      GameManager< struct GameMesh > meshes;
      std::vector< struct GameModel > models;

    };

    void InitContentManager( struct GameEngine* engine );

    void LoadTexture( struct GameContentManager* content_manager, std::string path );

    void LoadShader( struct GameContentManager* content_manager, std::string path );

    void LoadMesh( struct GameContentManager* content_manager, std::string path );

    bool LoadAsset( struct GameEngine* engine, enum EAssetTypes type, std::string path );

    void GenerateModel( struct GameEngine* engine );

    struct GameModel* FindModel( struct GameEngine* engine, unsigned int mesh );

    void* GetAsset( struct GameEngine* engine, enum EAssetTypes type, unsigned int index );

    void ClearContentManager( struct GameEngine* engine );

  };

#endif
