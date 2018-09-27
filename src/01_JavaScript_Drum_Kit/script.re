open Webapi.Dom;

let playSound = ({keyCode}) => {
  let audio = Document.querySelector({j|audio[data-key="$keyCode"]|j});
  let key = Document.querySelector({j|.key[data-key="$keyCode"]|j});
  if (audio) {
    audio.currentTime = 0;
    audio.play();
    key.classList.add("playing");
  };
};

let removePlayingClass = e =>
  if (e.propertyName === "transform") {
    e.target.classList.remove("playing");
  };

let keys = Document.querySelectorAll(".key");

keys.forEach(key =>
  key.addEventListener("transitionend", removePlayingClass)
);

Window.addEventListener("keydown", playSound);
