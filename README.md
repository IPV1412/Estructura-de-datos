# Proyecto Parcial 2 - Git

#### Jonathan Nava Noguez   IPV1412

#### Estructura de datos    ID: 6576

**Instrucciones:** Para este proyecto parcial cerraremos el tema de GIT, para ello van a realizar un documento en formato MarkDown en el cual expliquen el proceso por el cual se crea un repositorio local, se sube a GitHub y los comandos que hemos aprendido para interactuar con ellos:
commit, push, remote, add, rm, pull, checkout, branch, reset, revert, log y squashing(este ultimo no es un comando pero se maneja como un tema de la misma manera) recordando pasar por las variaciones o modos que se pueden trabajar en los comandos como el commit con y sin el -m o la diferencia entre checkout con un hash o con una rama.

---
## Git
**Git es un sistema de control de versiones distribuido que permite a los desarrolladores rastrear y gestionar los cambios en el código fuente de sus proyectos a lo largo del tiempo. 
Fue creado por Linus Torvalds en 2005, principalmente para gestionar el desarrollo del kernel de Linux, y desde entonces ha sido adoptado por una amplia comunidad de desarrolladores de software en todo el mundo.**
<br>

### Inicialización
Para empezar a usar Git,debes descargar git a ccediendo a la pagina de [Git](https://git-scm.com/download/win)
<br>
Primero necesitas crear un repositorio local, para ello usamos el comando _INIT_
```bash
   git init
   ```
Este comando crea un nuevo repositorio Git en el directorio actual.
<br>
En caso de ya tener un repositoria hay que clonarlo
   ```bash
   git clone <url>
   ```
Este comando descarga un repositorio existente desde una URL y lo clona en tu máquina local.

---

## Comandos de Git y Sus Variaciones
### Commit
El comando `git commit` se utiliza para confirmar los cambios en el área de preparación (staging area) y guardarlos en el historial del repositorio.
Cada commit crea un registro en el historial con un mensaje descriptivo y un identificador único.
<br>
```sh
git commit -m "Mensaje del commit"
```
Este comando realiza un commit de los cambios en el área de preparación con el mensaje especificado.
<br>
```sh
git commit -m "Mensaje del commit"
```
Esta es la forma más básica del comando, donde `-m` indica el mensaje del commit.
El mensaje debe describir brevemente los cambios realizados.
<br>
```sh
git commit -a -m "Mensaje del commit"
```
La opción `-a` automáticamente añade todos los archivos modificados (excluyendo nuevos archivos no rastreados) al área de preparación antes de realizar el commit.
<br>
```sh
git commit --amend -m "Mensaje actualizado"
```
El comando `--amend` permite modificar el último commit realizado, actualizando su mensaje o añadiendo más cambios.
<br>
```sh
git commit --allow-empty -m "Commit vacío"
```
Esta opción permite crear un commit sin cambios en el contenido, útil para marcar eventos en el historial.
<br>
```sh
git commit --squash <commit>
```
Combina el commit actual con el especificado, fusionando sus cambios y mensajes. 
Este comando se usa generalmente durante la rebase interactiva.
<br>
```sh
git commit --fixup <commit>
```
Crea un commit de corrección para un commit anterior especificado. 
Útil para corregir errores sin cambiar el orden de los commits.
<br>
```sh
git commit --verbose -m "Mensaje del commit"
```
Muestra el diff de los cambios que se están confirmando, proporcionando una vista detallada antes de realizar el commit.
<br>
```sh
git commit --template=<archivo>
```
Utiliza un archivo de plantilla para prellenar el mensaje del commit.
Esto es útil para seguir un formato específico para mensajes de commit.
<br>>
```sh
git commit --signoff -m "Mensaje del commit"
```
Añade una firma de conformidad al final del mensaje del commit, indicando que aceptas los términos de la contribución.
<br>
```sh
git commit --amend --reset-author -m "Mensaje del commit"
```
Restaura la información del autor del commit a la configuración global de Git, útil si necesitas cambiar el autor de un commit anterior.
<br>
---

### Push
Este comando envía los commits locales al repositorio remoto.

- **Push a la rama principal**:
  ```bash
  git push origin main
  ```
- **Envía los commits de la rama actual al repositorio remoto**:
  ```bash
  git push
  ```
- **Envía los commits de una rama específica al repositorio remoto**:
  ```bash
  git push origin <nombre_rama>
  ```
- **Elimina una rama en el repositorio remoto**:
  ```bash
  git push origin --delete <nombre_rama>
  ```
- **Fuerza el envío de los commits**:
  ```bash
  git push --force
  ```
---

### remote
Este comando gestiona las conexiones a los repositorios remotos.
### `remote`
Este comando gestiona las conexiones a repositorios remotos.

- **Lista todos los repositorios remotos**:
  ```bash
  git remote
  ```
- **Muestra la URL del repositorio remoto especificado**:
  ```bash
  git remote get-url <nombre_remoto>
  ```
- **Añade un nuevo repositorio remoto**:
  ```bash
  git remote add <nombre_remoto> <url_remoto>
  ```
- **Cambia la URL de un repositorio remoto**:
  ```bash
  git remote set-url <nombre_remoto> <nueva_url>
  ```
- **Elimina un repositorio remoto**:
  ```bash
  git remote remove <nombre_remoto>
  ```
- **Muestra información detallada de un repositorio remoto**:
  ```bash
  git remote show <nombre_remoto>
  ```
---

### add
Este comando añade archivos al área de preparación (staging area).

- **Añade un archivo específico**:
  ```bash
  git add <archivo>
  ```
- **Añade todos los archivos**:
  ```bash
  git add .
  ```
- **Añade un directorio especifico**:
  ```bash
  git add <directorio>
  ```
- **Inicia una interfaz interactiva para seleccionar los cambios a añadir al área de preparación.**:
  ```bash
  git add -i
  ```
- **Añade partes especificas del archivo**:
  ```bash
  git add -p
  ```
- **Añade archivos al área de preparación, incluso si están en la lista de .gitignore.**:
  ```bash
  git add -f <archivo>
  ```
  
---

### rm
Este comando elimina archivos del índice y del directorio de trabajo.

- **Eliminar un archivo**:
  ```bash
  git rm <archivo>
  ```
- **Eliminar un archivo pero mantenerlo en el directorio de trabajo**:
  ```bash
  git rm --cached <archivo>
  ```
- **Elimina un directorio y su contenido del área de trabajo y del índice**:
  ```bash
  git rm -r <directorio>
  ```

---

### pull
Este comando combina los cambios del repositorio remoto en la rama actual.

- **Descarga y fusiona los cambios del repositorio remoto en la rama actual**:
  ```bash
  git pull
  ```
- **Descarga y fusiona los cambios de una rama específica del repositorio remoto en la rama actual**:
  ```bash
  git pull <nombre_remoto> <nombre_rama>
  ```
- **Descarga y fusiona los cambios de una rama específica del repositorio remoto en la rama actual y reescribe la historia local con la del repositorio remoto**:
  ```bash
  git pull <nombre_remoto> <nombre_rama> --rebase
  ```
  
---

### checkout
Este comando se utiliza para cambiar entre ramas, restaurar archivos del área de trabajo y más.

- **Cambia a una rama existente**:
  ```bash
  git checkout <nombre_rama>
  ```
- **Crea una nueva rama y cambia a ella**:
  ```bash
  git checkout -b <nombre_nueva_rama>
  ```
- **Restaura un archivo específico del área de trabajo**:
  ```bash
  git checkout <archivo>
  ```
- **Restaura todos los archivos del área de trabajo**:
  ```bash
  git checkout .
  ```
---

### branch
Este comando se utiliza para listar, crear, eliminar y gestionar ramas en el repositorio.

- **Lista todas las ramas locales**:
  ```bash
  git branch
  ```
- **Crea una nueva rama**:
  ```bash
  git branch <nombre_rama>
  ```
- **Elimina una rama**:
  ```bash
  git branch -d <nombre_rama>
  ```
- **Elimina una rama de manera forzada**:
  ```bash
  git branch -D <nombre_rama>
  ```
- **Renombra una rama**:
  ```bash
  git branch -m <nombre_nuevo>
  ```
  
---

### reset
Este comando se utiliza para deshacer cambios en el repositorio.

- **Deshace cambios en el área de preparación y en el directorio de trabajo, pero conserva los cambios en los archivos**:
  ```bash
  git reset HEAD <archivo>
  ```
- **Deshace cambios en el área de preparación y en el directorio de trabajo, eliminando los cambios realizados**:
  ```bash
  git reset --hard HEAD
  ```
- **Deshace cambios en el área de preparación, pero conserva los cambios en el directorio de trabajo**:
  ```bash
  git reset --mixed HEAD
  ```
- **Deshace y elimina los commits posteriores al commit especificado, conservando los cambios locales**:
  ```bash
  git reset --soft <commit>
  ```
- **Deshace y elimina los commits posteriores al commit especificado, eliminando también los cambios locales**:
  ```bash
  git reset --hard <commit>
  ```
  
---

### revert
Este comando se utiliza para deshacer un commit existente creando un nuevo commit que revierte los cambios realizados por el commit original.

- **Deshace el commit especificado creando un nuevo commit con los cambios revertidos**:
  ```bash
  git revert <hash_del_commit>
  ```
- **Deshace múltiples commits especificados creando nuevos commits para revertir los cambios de cada uno**:
  ```bash
  git revert <hash_del_commit_1> <hash_del_commit_2> ...
  ```
- **Revierte el último commit realizado en la rama actual**:
  ```bash
  git revert HEAD
  ```
  
---

### log
Este comando muestra el historial de commits del repositorio.

- **Muestra el historial de commits**:
  ```bash
  git log
  ```
- **Muestra el historial con detalles de cada commit**:
  ```bash
  git log --stat
  ```
- **Muestra el historial con un gráfico de ramas**:
  ```bash
  git log --graph
  ```
- **Muestra un historial simplificado con un gráfico**:
  ```bash
  git log --oneline --graph
  ```
- **Muestra el historial de un archivo específico**:
  ```bash
  git log <archivo>
  ```

---  

#### Squashing
#### ¿Qué es?
Squashing es un proceso en Git que combina varios commits en uno solo. 
Es útil para limpiar el historial de commits y hacer que la historia del proyecto sea más legible al agrupar cambios relacionados en un solo commit.
<br>
#### Cómo usarlo en Git
Para utilizar el squashing en Git, puedes seguir estos pasos:

1. **Identifica los commits que quieres combinar**: Utiliza el comando `git log` para ver el historial de commits y anota los hashes de los commits que deseas agrupar.

2. **Inicia el proceso de rebase interactivo**: Utiliza el siguiente comando para iniciar el proceso de rebase interactivo hasta el commit anterior al primer commit que deseas combinar:
   ```bash
   git rebase -i HEAD~n
   ```
   Donde `n` es el número de commits que deseas incluir en el squashing.

3. **Se abrirá un editor de texto con la lista de commits**: Verás una lista de commits con la palabra `pick` al principio de cada línea. Cambia la palabra `pick` por `squash` o simplemente `s` para los commits que deseas combinar. Mantén `pick` para el commit que deseas mantener sin cambios.

4. **Guarda y cierra el editor de texto**: Una vez que hayas terminado de editar, guarda y cierra el editor de texto.

5. **Git combinará los commits seleccionados**: Git combinará los commits seleccionados en uno solo y abrirá otro editor de texto para que puedas escribir un nuevo mensaje de commit para el commit combinado. Puedes mantener el mensaje predeterminado o escribir uno nuevo.

6. **Guarda y cierra el editor de texto**: Una vez que hayas escrito el mensaje de commit, guarda y cierra el editor de texto.

7. **Finaliza el rebase**: Finaliza el rebase con el siguiente comando:

   ```bash
   git rebase --continue
   ```
   Si todo salió bien, Git aplicará los cambios y finalizará el rebase.

8. **Actualiza el repositorio remoto (si es necesario)**: Si has realizado cambios en commits que ya has compartido con otros, es posible que necesites forzar la actualización del repositorio remoto:
   ```bash
   git push --force
   ```
   Asegúrate de tener cuidado al forzar la actualización del repositorio remoto, ya que puede sobrescribir el historial de commits de otros colaboradores.

# Listo
 Ahora has combinado varios commits en uno solo utilizando el squashing en Git. Muy util para evitar el ataque del temible pasante.

---

IEEE
- “Git - Descarga del paquete.” https://git-scm.com/download/win
- “Git - documentación.” https://git-scm.com/doc
