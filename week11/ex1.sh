fallocate -l 50M lofs.img
LOOP_NUMBER=$(sudo losetup -f)
sudo losetup -f lofs.img
sudo mkfs.ext4 "${LOOP_NUMBER}"
mkdir lofsdisk
sudo mount "${LOOP_NUMBER}" lofsdisk